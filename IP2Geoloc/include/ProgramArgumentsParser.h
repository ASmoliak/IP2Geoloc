#pragma once
#include "pch.h"

namespace program_options = boost::program_options;

struct Settings
{
	std::string IPv4_to_scan = "";
	bool resolve_self = false;
};

class ProgramArgumentsParser
{
public:
	ProgramArgumentsParser(int argument_count, const char *arguments[]);

	Settings getParsedSettings();

private:
	void throwOnConflictingArguments(int argument_count, const char *arguments[]);
	void generateOptions();
	void storeArguments(int argument_count, const char *arguments[]);
	void printHelp();

	program_options::options_description _program_options = program_options::options_description("Allowed options");
	program_options::variables_map _variables;
};