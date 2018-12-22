IPtoGeolocConverter::IPtoGeolocConverter()
{
}

IPtoGeolocConverter::~IPtoGeolocConverter()
{
}

Geolocation IPtoGeolocConverter::convertIPtoGeoloc(const std::string& IPv4)
{
	std::stringstream full_geoloc_in_json;
	full_geoloc_in_json << _requestor.requestGeolocFromIP(IPv4);
	GeolocParser response_parser(full_geoloc_in_json);

	return Geolocation(
		response_parser.getCountry(),
		response_parser.getRegionName(),
		response_parser.getCity());
}