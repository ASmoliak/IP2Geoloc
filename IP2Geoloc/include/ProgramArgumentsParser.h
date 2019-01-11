#pragma once
#include "pch.h"

namespace program_options = boost::program_options;

struct Settings
{
	std::string IPv4_to_scan;
	bool resolve_self;
};

class ProgramArgumentsParser
{
public:
	ProgramArgumentsParser(int argument_count, const char *arguments[]);

	Settings getParsedSettings();

private:
	void generateOptions();
	void storeArguments(int argument_count, const char *arguments[]);
	void validateArguments();
	void searchForConflictingArguments();
	void printHelp();

	program_options::options_description _program_options = program_options::options_description("Allowed options");
	program_options::variables_map _variables;
};