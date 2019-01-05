#include "pch.h"
#include "../IP2Geoloc/ProgramArgumentsParser.h"

// Valid Input Data
int _valid_argument_count = 3;
char *_valid_target_IP = "8.8.8.8";
char *_valid_arguments[] = { "C:\\Users\\Luka\\source\\repos\\IP2Geoloc Tool\\Unit Testing\\IP2Geoloc.exe", "--ip", _valid_target_IP };

TEST(ProgramArgumentsParser_Tests, IPv4_Result_Validity)
{
	ProgramArgumentsParser parser(_valid_argument_count, _valid_arguments);
	Settings result = parser.getParsedSettings();

	bool areValuesEqual = !strcmp(_valid_target_IP, result.IPv4_to_scan.c_str());
	EXPECT_TRUE(areValuesEqual) << "The input IP argument is not the same as the parsed IP in Settings";
}

TEST(ProgramArgumentsParser_Tests, Bad_Argument_Count)
{
	int invalid_argument_count = 2;

	ProgramArgumentsParser *parser = nullptr;
	EXPECT_ANY_THROW(parser = new ProgramArgumentsParser(invalid_argument_count, _valid_arguments)) << "Our code did not throw an exception on invalid argument count";
}