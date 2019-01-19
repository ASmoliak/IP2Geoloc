#pragma once
#include "pch.h"

#include "GeolocRequestor.h"

class Ip2cRequestor : public GeolocRequestor
{
public:
	Ip2cRequestor();

private:
	virtual http_request generateGeolocRequest(const std::string &IPv4);

	static constexpr auto PROVIDER_HOSTNAME = "www.ip2c.org";
	static constexpr auto PROVIDER_PORT = "80";
	static constexpr auto PROVIDER_HTTP_VERSION = 11;
};
