#include "pch.h"

#include <string>
#include <sstream>

#include "IPtoGeolocConverter.h"
#include "GeolocResponseAdapter.h"
#include "GeolocRequestor.h"

Geolocation IPtoGeolocConverter::convertIPtoGeoloc(const std::string &IPv4)
{
	std::stringstream geoloc_in_json;
	GeolocRequestor requestor;
	geoloc_in_json << requestor.requestGeolocFromIP(IPv4);
	GeolocResponseAdapter response_parser(geoloc_in_json);

	return Geolocation(
		response_parser.getCountry(),
		response_parser.getRegionName(),
		response_parser.getCity());
}