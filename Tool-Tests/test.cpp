#include "pch.h"

TEST(ProgramArgumentsParser_Tests, IPv4_Result_Validity)
{
	int argc = 3;
	char *target_IP = "8.8.8.8";
	char *argv[] = { "C:\\Users\\Luka\\source\\repos\\IP2Geoloc Tool\\Unit Testing\\IP2Geoloc.exe", "--ip", target_IP };

	ProgramArgumentsParser parser(argc, argv);
	Settings result = parser.getParsedSettings();

	EXPECT_EQ("8.8.8.8", result.IPv4_to_scan.c_str());
}