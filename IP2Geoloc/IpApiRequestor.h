#pragma once
#include "pch.h"

#include "GeolocRequestor.h"

class IpApiRequestor : public GeolocRequestor
{
public:
	IpApiRequestor();

private:
	virtual http_request generateGeolocRequest(const std::string &IPv4);

	static constexpr auto PROVIDER_HOSTNAME = "www.ip-api.com";
	static constexpr auto PROVIDER_PORT = "80";
	static constexpr auto PROVIDER_HTTP_VERSION = 11;
};
