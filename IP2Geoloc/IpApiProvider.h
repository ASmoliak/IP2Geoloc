#pragma once
#include "pch.h"

#include "IpApiRequestor.h"
#include "IpApiResponseAdapter.h"
#include "Geolocation.h"

// Geolocation Provider: www.ip-api.com
// Format: JSON
class IpApiProvider
{
public:
	IpApiProvider();
	
	Geolocation getParsedGeolocationOfIP(const std::string &IPv4);

private:
	IpApiRequestor _requestor;
};
