#include "pch.h"

#include <string>
#include <sstream>

#include "IPtoGeolocConverter.h"
#include "GeolocResponseAdapter.h"
#include "GeolocRequestor.h"

Geolocation IPtoGeolocConverter::resolveIPtoGeoloc(const std::string &IPv4)
{
	if (IPv4 != "")
	{
		validateIP(IPv4);
	}

	std::stringstream geoloc_in_json;
	GeolocRequestor requestor;
	geoloc_in_json << requestor.requestGeolocFromIP(IPv4);
	GeolocResponseAdapter response_parser(geoloc_in_json);

	return Geolocation(
		response_parser.getCountry(),
		response_parser.getRegionName(),
		response_parser.getCity());
}

void IPtoGeolocConverter::validateIP(const std::string &IPv4_address)
{
	boost::system::error_code error_code;
	auto raw_ipv4_address = boost::asio::ip::address::from_string(IPv4_address, error_code);
	if (error_code)
	{
		throw std::invalid_argument("Input IPv4 address is invalid");
	}

	std::string raw_to_string_form = raw_ipv4_address.to_string();
	if (raw_to_string_form.compare(IPv4_address))
	{
		throw std::invalid_argument("Input IPv4 address is invalid");
	}
}