#include "pch.h"

#include "IpApiRequestor.h"

IpApiRequestor::IpApiRequestor(const std::string &providerHostName, const std::string &providerPort, int httpVersionToUse) :
	GeolocRequestor(providerHostName, providerPort, httpVersionToUse)
{
}

http_request IpApiRequestor::generateGeolocRequest(const std::string &IPv4)
{
	std::string target_url = "/json/" + IPv4;
	http_request request{ http::verb::get, target_url, _httpVersionToUse};
	request.set(http::field::host, _providerHostName);
	request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

	return request;
}