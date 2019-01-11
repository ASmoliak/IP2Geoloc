#include "pch.h"

#include <iostream>
#include <string>

#include "ProgramArgumentsParser.h"

ProgramArgumentsParser::ProgramArgumentsParser(int argument_count, const char *arguments[])
{
	generateOptions();
	storeArguments(argument_count, arguments);
}

void ProgramArgumentsParser::generateOptions()
{
	_program_options.add_options()
		("help", "Produce help message")
		("ip", program_options::value<std::string>(), "Set the IP to get geolocation information for.")
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

	if (_variables.count("help"))
	{
		printHelp();
		exit(0);
	}
	if (_variables.count("ip"))
	{
		generated_settings.IPv4_to_scan = _variables["ip"].as<std::string>();
	}

	return generated_settings;
}

void ProgramArgumentsParser::printHelp()
{
	std::cout << _program_options << std::endl;
}