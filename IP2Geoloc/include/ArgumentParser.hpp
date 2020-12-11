#pragma once
#include <iostream>
#include <string>
#include <vector>

#include <boost/program_options.hpp>

struct Settings
{
	std::string IPv4_to_scan = "";
	bool resolve_self = false;
};

class ArgumentParser
{
	struct OptionNames
	{
		static constexpr auto HELP = "help";
		static constexpr auto IP = "ip";
		static constexpr auto SELF = "self";
	};

	boost::program_options::options_description _program_options = boost::program_options::options_description("Allowed options");
	boost::program_options::variables_map _variables;

public:
	ArgumentParser(int argument_count, const char* arguments[])
	{
		throwOnConflictingArguments(argument_count, arguments);
		generateOptions();
		storeArguments(argument_count, arguments);
	}

	Settings getParsedSettings()
	{
		Settings generated_settings;

		if (!_variables.size() || _variables.count(OptionNames::HELP))
		{
			printHelp();
			exit(0);
		}
		if (_variables.count(OptionNames::IP))
		{
			generated_settings.IPv4_to_scan = _variables[OptionNames::IP].as<std::string>();
		}
		if (_variables.count(OptionNames::SELF))
		{
			generated_settings.resolve_self = true;
		}

		return generated_settings;
	}

private:
	void throwOnConflictingArguments(int argument_count, const char* arguments[])
	{
		std::vector<std::string> conflicting_options_vector = { OptionNames::HELP, OptionNames::IP, OptionNames::SELF };
		std::vector<std::string> arguments_vector(arguments, arguments + argument_count);

		bool conflictingOptionFound = false;

		for (auto const& conflicting_option : conflicting_options_vector)
		{
			for (auto const& argument : arguments_vector)
			{
				std::string full_option = "--" + conflicting_option;

				if (full_option != argument)
				{
					continue;
				}

				if (conflictingOptionFound)
				{
					throw std::invalid_argument("Conflicting options in argument parsing");
				}

				conflictingOptionFound = true;
			}
		}
	}

	void generateOptions()
	{
		_program_options.add_options()
			(OptionNames::HELP, "Produce this help message")
			(OptionNames::SELF, "Resolve self IP")
			(OptionNames::IP, boost::program_options::value<std::string>(), "Set the IP to get geolocation information for")
			;
	}

	void storeArguments(int argument_count, const char* arguments[])
	{
		auto parsed_cmd = boost::program_options::parse_command_line(argument_count, arguments, _program_options);

		boost::program_options::store(parsed_cmd, _variables);
		boost::program_options::notify(_variables);
	}

	void printHelp()
	{
		std::cout << _program_options << std::endl;
	}
};