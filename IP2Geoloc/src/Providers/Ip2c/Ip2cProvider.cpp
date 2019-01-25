#include "pch.h"

#include <string>
#include <sstream>

#include "Ip2cProvider.h"
#include "Ip2cResponseAdapter.h"

Ip2cProvider::Ip2cProvider() :
	_requestor()
{
}

Geolocation Ip2cProvider::getParsedGeolocationOfIP(const std::string &IPv4)
{
	std::string response_in_json = _requestor.requestGeoloctionOfIPV4(IPv4);

	Ip2cResponseAdapter response_adapter(response_in_json);
	
	return static_cast<Geolocation>(response_adapter);
}
