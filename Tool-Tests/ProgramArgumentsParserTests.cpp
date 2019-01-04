#include "pch.h"

int _valid_argument_count = 3;
char *_valid_target_IP = "8.8.8.8";
char *_valid_arguments[] = { "C:\\Users\\Luka\\source\\repos\\IP2Geoloc Tool\\Unit Testing\\IP2Geoloc.exe", "--ip", _valid_target_IP };

struct ProgramArgumentsParserData
{
	ProgramArgumentsParserData(int argc, const std::string ipv4, const std::vector<std::string> argv, bool expect_to_succeed) :
		_argument_count(argc), _target_IP(ipv4), _arguments(argv), _expect_to_succeed(expect_to_succeed)
	{
	}

	int _argument_count;
	const std::string _target_IP;
	const std::vector<std::string> _arguments;
	bool _expect_to_succeed;
};

struct ProgramArgumentsParserDataTest : public testing::Test
{
	ProgramArgumentsParserData *test_data;
	void SetUp()
	{
		std::string target_IP = "8.8.8.8";
		std::vector<std::string> argv = { "C:\\Users\\Luka\\source\\repos\\IP2Geoloc Tool\\Unit Testing\\IP2Geoloc.exe",
			"--ip", target_IP };
		test_data = new ProgramArgumentsParserData(3, "8.8.8.8", argv, true);
	}

	void TearDown()
	{
		delete test_data;
	}
};

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

TEST(ProgramArgumentsParser_Tests, Invalid_IPv4_address)
{
	char *invalid_target_IP = "8.8.88";
	char *invalid_arguments[] = { "C:\\Users\\Luka\\source\\repos\\IP2Geoloc Tool\\Unit Testing\\IP2Geoloc.exe", "--ip", invalid_target_IP };
	
	ProgramArgumentsParser *parser = nullptr;
	EXPECT_ANY_THROW(parser = new ProgramArgumentsParser(_valid_argument_count, invalid_arguments)) << "Our code did not throw an exception on invalid IPv4 address";
}