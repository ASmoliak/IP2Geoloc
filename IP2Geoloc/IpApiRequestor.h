#pragma once
#include "pch.h"

#include "GeolocRequestor.h"

// Provider: www.ip-api.com
// Format: JSON
class IpApiRequestor : public GeolocRequestor
{
public:
	IpApiRequestor(const std::string &providerHostName, const std::string &providerPort, int httpVersionToUse);

private:
	virtual http_request GeolocRequestor::generateGeolocRequest(const std::string &IPv4);
};