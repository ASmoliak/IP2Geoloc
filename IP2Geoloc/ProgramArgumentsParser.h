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
	// Constructor and destructor
	ProgramArgumentsParser(int argumentCount, char *arguments[]);
	~ProgramArgumentsParser();

	// Public member functions
	Settings getParsedSettings();

private:
	// Private member functions
	void storeArguments(int argumentCount, char* arguments[]);
	void generateOptions();
	void printHelp();

	// Private member variables
	program_options::options_description _programOptions = program_options::options_description("Allowed options");
	program_options::variables_map _variables;
};