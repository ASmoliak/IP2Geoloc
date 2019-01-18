#pragma once
#include "pch.h"

#include "GeolocRequestor.h"

class IpApiRequestor : public GeolocRequestor
{
public:
	IpApiRequestor(const std::string &providerHostName, const std::string &providerPort, int httpVersionToUse);

private:
	virtual http_request generateGeolocRequest(const std::string &IPv4);
};
