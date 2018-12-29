#include "pch.h"

#include <string>
#include <sstream>

#include "IPtoGeolocConverter.h"
#include "GeolocParser.h"
#include "GeolocRequestor.h"

Geolocation IPtoGeolocConverter::convertIPtoGeoloc(const std::string &IPv4)
{
	std::stringstream full_geoloc_in_json;
	GeolocRequestor requestor;
	full_geoloc_in_json << requestor.requestGeolocFromIP(IPv4);
	GeolocParser response_parser(full_geoloc_in_json);

	return Geolocation(
		response_parser.getCountry(),
		response_parser.getRegionName(),
		response_parser.getCity());
}