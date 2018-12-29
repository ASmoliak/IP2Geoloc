GeolocParser::GeolocParser(std::stringstream& json_content)
{
	property_tree::read_json(json_content, _root_of_tree);
}

GeolocParser::GeolocParser(const std::string& json_file_name)
{
	property_tree::read_json(json_file_name, _root_of_tree);
}

std::string GeolocParser::getCountry()
{
	return _root_of_tree.get<std::string>("country");;
}

std::string GeolocParser::getRegionName()
{
	return _root_of_tree.get<std::string>("regionName");;
}

std::string GeolocParser::getCity()
{
	return _root_of_tree.get<std::string>("city");;
}