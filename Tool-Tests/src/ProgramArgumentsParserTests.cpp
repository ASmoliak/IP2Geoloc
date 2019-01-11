#include "pch.h"
#include "../IP2Geoloc/include/ProgramArgumentsParser.h"

constexpr auto VALID_TARGET_IP = "8.8.8.8";
constexpr auto PROGARM_PATH = "C:\\Users\\Luka\\source\\repos\\IP2Geoloc Tool\\bin\\Unit Testing\\IP2Geoloc.exe";
constexpr auto IP_ARGUMENT = "--ip";
constexpr auto SELF_RESOLVE_ARGUMENT = "--self";

TEST(ProgramArgumentsParser_Tests, IPv4_Result_Validity)
{
	const char *valid_resolve_arguments[] = { PROGARM_PATH, IP_ARGUMENT, VALID_TARGET_IP };
	int valid_argument_count = 3;

	ProgramArgumentsParser parser(valid_argument_count, valid_resolve_arguments);
	Settings result = parser.getParsedSettings();

	bool areValuesEqual = !strcmp(VALID_TARGET_IP, result.IPv4_to_scan.c_str());
	EXPECT_TRUE(areValuesEqual) << "The input IP argument is not the same as the parsed IP in Settings";
}

TEST(ProgramArgumentsParser_Tests, Bad_Argument_Count)
{
	const char *valid_resolve_arguments[] = { PROGARM_PATH, IP_ARGUMENT, VALID_TARGET_IP };
	int valid_argument_count = 2;

	ProgramArgumentsParser *parser = nullptr;
	EXPECT_ANY_THROW(parser = new ProgramArgumentsParser(valid_argument_count, valid_resolve_arguments)) 
		<< "Our code did not throw an exception on invalid argument count";
}

TEST(ProgramArgumentsParser_Tests, Self_Result_Validity)
{
	const char *valid_resolve_arguments[] = { PROGARM_PATH, SELF_RESOLVE_ARGUMENT };
	int valid_argument_count = 3;

	ProgramArgumentsParser parser(valid_argument_count, valid_resolve_arguments);
	Settings result = parser.getParsedSettings();

	EXPECT_TRUE(result.resolve_self) << "The settings struct's resolve self boolean was not set to true on correct input";
}