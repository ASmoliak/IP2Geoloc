GeolocationDetailsParser::GeolocationDetailsParser(std::stringstream json_content)
{
	property_tree::read_json(json_content, _root_of_tree);
	readGeolocationInfo();
}

GeolocationDetailsParser::GeolocationDetailsParser(const std::string& json_file_name)
{
	property_tree::read_json(json_file_name, _root_of_tree);
	readGeolocationInfo();
}

void GeolocationDetailsParser::readGeolocationInfo()
{
	_country = _root_of_tree.get<std::string>("country");
	_regionName = _root_of_tree.get<std::string>("regionName");
	_city = _root_of_tree.get<std::string>("city");
}

std::string GeolocationDetailsParser::getCountry()
{
	return _country;
}

std::string GeolocationDetailsParser::getRegionName()
{
	return _regionName;
}

std::string GeolocationDetailsParser::getCity()
{
	return _city;
}
