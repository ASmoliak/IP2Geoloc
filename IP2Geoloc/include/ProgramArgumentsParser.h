#pragma once
#include "pch.h"

namespace program_options = boost::program_options;

struct Settings
{
	std::string IPv4_to_scan;
};

class ProgramArgumentsParser
{
public:
	ProgramArgumentsParser(int argument_count, char *arguments[]);

	Settings getParsedSettings();

private:
	void generateOptions();
	void storeArguments(int argument_count, char *arguments[]);
	void printHelp();

	program_options::options_description _program_options = program_options::options_description("Allowed options");
	program_options::variables_map _variables;
};