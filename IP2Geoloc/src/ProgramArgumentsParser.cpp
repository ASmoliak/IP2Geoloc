#include "pch.h"

#include <iostream>
#include <string>

#include "ProgramArgumentsParser.h"

namespace OptionNames
{
	constexpr auto HELP = "help";
	constexpr auto IP = "ip";
	constexpr auto SELF = "self";
}

ProgramArgumentsParser::ProgramArgumentsParser(int argument_count, const char *arguments[])
{
	throwOnConflictingArguments(argument_count, arguments);
	generateOptions();
	storeArguments(argument_count, arguments);
}

void ProgramArgumentsParser::throwOnConflictingArguments(int argument_count, const char *arguments[])
{
	std::vector<std::string> conflicting_options_vector = { OptionNames::HELP, OptionNames::IP, OptionNames::SELF };
	std::vector<std::string> arguments_vector(arguments, arguments + argument_count);

	bool conflictingOptionFound = false;

	for (auto const &conflicting_option : conflicting_options_vector)
	{
		for(auto const &argument : arguments_vector)
		{
			std::string full_option = "--" + conflicting_option;

			if(0 == full_option.compare(argument))
			{
				if (conflictingOptionFound)
				{
					throw std::invalid_argument("Conflicting options in argument parsing");
				}
				else
				{
					conflictingOptionFound = true;
				}
			}
		}
	}
}

void ProgramArgumentsParser::generateOptions()
{
	_program_options.add_options()
		(OptionNames::HELP, "Produce this help message")
		(OptionNames::SELF, "Resolve self IP")
		(OptionNames::IP, program_options::value<std::string>(), "Set the IP to get geolocation information for")
		;
}

void ProgramArgumentsParser::storeArguments(int argument_count, const char *arguments[])
{	
	program_options::store(program_options::parse_command_line(argument_count, arguments, _program_options), _variables);
	program_options::notify(_variables);
}


Settings ProgramArgumentsParser::getParsedSettings()
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

void ProgramArgumentsParser::printHelp()
{
	std::cout << _program_options << std::endl;
}