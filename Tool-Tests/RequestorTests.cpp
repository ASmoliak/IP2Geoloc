#include "pch.h"

#include "GeolocRequestor.h"
#include "IpApiRequestor.h"
#include "Ip2cRequestor.h"

constexpr auto VALID_TARGET_IP = "8.8.8.8";

TEST(RequestorTests, ipApiRequestor)
{
	IpApiRequestor requestor_under_testing;
	std::string actual_response = requestor_under_testing.requestGeoloctionOfIPV4(VALID_TARGET_IP);

	EXPECT_TRUE(actual_response.size() > 0);
}

TEST(RequestorTests, Ip2cRequestor)
{
	Ip2cRequestor requestor_under_testing;
	std::string actual_response = requestor_under_testing.requestGeoloctionOfIPV4(VALID_TARGET_IP);

	auto search_result = actual_response.find("Bad Request");
	bool isBadRequest = search_result != std::string::npos;
	EXPECT_FALSE(isBadRequest);
}