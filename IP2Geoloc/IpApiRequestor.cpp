#include "pch.h"

#include "IpApiRequestor.h"

IpApiRequestor::IpApiRequestor() :
	GeolocRequestor(PROVIDER_HOSTNAME, PROVIDER_PORT, PROVIDER_HTTP_VERSION)
{
}

http_request IpApiRequestor::generateGeolocRequest(const std::string &IPv4)
{
	std::string target_url = "/json/" + IPv4;
	http_request request{ http::verb::get, target_url, _httpVersionToUse };
	request.set(http::field::host, _providerHostName);
	request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

	return request;
}
