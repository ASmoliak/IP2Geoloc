#pragma once
#include "pch.h"

#include "Ip2cRequestor.h"
#include "Ip2cResponseAdapter.h"
#include "Geolocation.h"

// Geolocation Provider: www.ip-api.com
// Format: CSV
class Ip2cProvider
{
public:
	Ip2cProvider();

	Geolocation getParsedGeolocationOfIP(const std::string &IPv4);

private:
	Ip2cRequestor _requestor;
};
