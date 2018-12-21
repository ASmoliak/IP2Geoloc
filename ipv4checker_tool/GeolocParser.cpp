GeolocParser::GeolocParser(std::stringstream json_content)
{
	property_tree::read_json(json_content, _root_of_tree);
	readGeolocationInfo();
}

GeolocParser::GeolocParser(const std::string& json_file_name)
{
	property_tree::read_json(json_file_name, _root_of_tree);
	readGeolocationInfo();
}

void GeolocParser::readGeolocationInfo()
{
	_country = _root_of_tree.get<std::string>("country");
	_regionName = _root_of_tree.get<std::string>("regionName");
	_city = _root_of_tree.get<std::string>("city");
}

std::string GeolocParser::getCountry()
{
	return _country;
}

std::string GeolocParser::getRegionName()
{
	return _regionName;
}

std::string GeolocParser::getCity()
{
	return _city;
}
