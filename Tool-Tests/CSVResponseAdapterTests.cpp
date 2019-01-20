#include "pch.h"
#include "GeolocCSVResponseAdapter.h"


class TestResponseAdapterForCSV : GeolocCSVResponseAdapter
{
public:
	TestResponseAdapterForCSV(const std::string &inputCSV) :
		GeolocCSVResponseAdapter(inputCSV)
	{
	}

	std::string getCountry()
	{
		if (_tokens.at(0) == "1")
		{
			return _tokens.at(3);
		}
		else
		{
			return "N/A";
		}
	}
};

TEST(CSVResposneAdapterTests, validInput)
{
	std::string CSV_Sample_Data = "1;IL;ISR;Israel";
	std::string expected_result = "Israel";

	TestResponseAdapterForCSV testCSVAdapter(CSV_Sample_Data);
	std::string actual_result = testCSVAdapter.getCountry();
	bool isResultCorrectCountry = (0 == actual_result.compare(expected_result));
	EXPECT_TRUE(isResultCorrectCountry);
}