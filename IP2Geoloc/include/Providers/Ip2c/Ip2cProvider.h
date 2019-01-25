#pragma once
#include "pch.h"

#include "Ip2cRequestor.h"
#include "Ip2cResponseAdapter.h"

// Geolocation Provider: www.ip-api.com
// Format: CSV
typedef Ip2cResponseAdapter Geolocation;

class Ip2cProvider
{
public:
	Ip2cProvider();

	Geolocation getParsedGeolocationOfIP(const std::string &IPv4);

private:
	Ip2cRequestor _requestor;
};
