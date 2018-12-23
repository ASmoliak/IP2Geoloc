#include "pch.h"

ProgramArgumentsParser::ProgramArgumentsParser(int argumentCount, char *arguments[])
{
	generateOptions();
	storeArguments(argumentCount, arguments);
}

ProgramArgumentsParser::~ProgramArgumentsParser()
{
}

void ProgramArgumentsParser::storeArguments(int argumentCount, char* arguments[])
{
	program_options::store(program_options::parse_command_line(argumentCount, arguments, _programOptions), _variables);
	program_options::notify(_variables);
}

Settings ProgramArgumentsParser::getParsedSettings()
{
	Settings generatedSettings;

	if (_variables.count("help"))
	{
		printHelp();
		exit(0);
	}
	if (_variables.count("ip"))
	{
		generatedSettings.IPv4_to_scan = _variables["ip"].as<std::string>();
	}

	return generatedSettings;
}

void ProgramArgumentsParser::generateOptions()
{
	_programOptions.add_options()
		("help", "Produce help message")
		("ip", program_options::value<std::string>(), "Set the IP to get geolocation information for.")
		;
}

void ProgramArgumentsParser::printHelp()
{
	std::cout << _programOptions << std::endl;
}