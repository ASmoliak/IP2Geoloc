#include "pch.h"

#include <string>
#include <sstream>

#include "Ip2cProvider.h"
#include "Ip2cResponseAdapter.h"
#include "Geolocation.h"

Ip2cProvider::Ip2cProvider() :
	_requestor()
{
}

Geolocation Ip2cProvider::getParsedGeolocationOfIP(const std::string &IPv4)
{
	std::string response_in_json = _requestor.requestGeoloctionOfIPV4(IPv4);

	std::stringstream converted_json_response_for_adapter = std::stringstream() << response_in_json;
	//Ip2cResponseAdapter response_adapter(converted_json_response_for_adapter);

	/*Geolocation parsedGeolocation(
		response_adapter.getCountry(),
		response_adapter.getRegionName(),
		response_adapter.getCity()
	);*/

	//return parsedGeolocation;
	return Geolocation();
}
