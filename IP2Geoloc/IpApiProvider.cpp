#include "pch.h"

#include "IpApiProvider.h"

IpApiProvider::IpApiProvider() :
	_requestor()
{
}

Geolocation IpApiProvider::getParsedGeolocationOfIP(const std::string &IPv4)
{
	std::string response_in_json = _requestor.requestGeoloctionOfIPV4(IPv4);
	
	std::stringstream converted_json_response_for_adapter = std::stringstream() << response_in_json;
	IpApiResponseAdapter response_adapter(converted_json_response_for_adapter);

	Geolocation parsedGeolocation(
		response_adapter.getCountry(),
		response_adapter.getRegionName(),
		response_adapter.getCity()
	);

	return parsedGeolocation;
}
