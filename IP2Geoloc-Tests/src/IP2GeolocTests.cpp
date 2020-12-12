#include "gtest/gtest.h"

#include "IP2Geoloc.hpp"

TEST(IP2GeolocTests, ValidAddressesWork)
{
	std::string valid_IPv4_address = "8.8.8.8";
	IP2Geoloc::Geolocation expected_result("United States", "California", "Mountain View");

	IP2Geoloc ip2geoloc;
	auto actual_result = ip2geoloc.resolve(valid_IPv4_address);

	EXPECT_TRUE(actual_result == expected_result) << 
				"The resolved Geolocation info is not the same as the expected Geolocation";
}

TEST(IP2GeolocTests, InvalidAddressesThrow)
{
	std::vector<std::string> invalid_IPv4_addresses = { "I am an address!", "8.8.88", "1111", "4124asdf", "Dafsdr2345@#$", "0x1.0x2.0x3" };

	IP2Geoloc ip2geoloc;
	for (const auto &invalid_IPv4_adress : invalid_IPv4_addresses)
	{
		EXPECT_THROW(ip2geoloc.resolve(invalid_IPv4_adress), std::invalid_argument) <<
			"We did not throw an exception on an invalid IPv4 address when resolving";
	}
}