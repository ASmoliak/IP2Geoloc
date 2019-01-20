#include "pch.h"

#include "Ip2cRequestor.h"

Ip2cRequestor::Ip2cRequestor() :
	GeolocRequestor(PROVIDER_HOSTNAME, PROVIDER_PORT, PROVIDER_HTTP_VERSION)
{
}

http_request Ip2cRequestor::generateGeolocRequest(const std::string &IPv4)
{
	std::string target_url = "/";
	if (IPv4 == "")
	{
		target_url += "self";
	}
	else
	{
		target_url += IPv4;
	}
	http_request request{ http::verb::get, target_url, _httpVersionToUse };
	request.set(http::field::host, _providerHostName);
	request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

	return request;
}
