#include "pch.h"
#include "../IP2Geoloc/include/IPtoGeolocConverter.h"

TEST(IPToGeolocConverterTests, Valid_IPv4_Input)
{
	std::string valid_IPv4_address = "8.8.8.8";
	Geolocation expected_result("United States", "California", "Mountain View");

	Geolocation actual_result = IPtoGeolocConverter::convertIPtoGeoloc(valid_IPv4_address);

	bool areResultsValid = actual_result == expected_result;
	EXPECT_TRUE(areResultsValid) << "The resolved Geolocation info is not the same as the expected Geolocation";
}

TEST(IPToGeolocConverterTests, Invalid_IPv4_Input)
{
	std::vector<std::string> invalid_IPv4_addresses = { "I am an address!", "8.8.88", "1111", "4124asdf", "Dafsdr2345@#$" };

	for (const auto &invalid_IPv4_adress : invalid_IPv4_addresses)
	{
		EXPECT_ANY_THROW(IPtoGeolocConverter::convertIPtoGeoloc(invalid_IPv4_adress)) <<
			"We did not throw an exception on an invalid IPv4 address when resolving";
	}
}