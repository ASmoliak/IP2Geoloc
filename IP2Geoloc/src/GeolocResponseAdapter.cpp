#include "pch.h"

#include <sstream>
#include <string>

#include "GeolocResponseAdapter.h"

GeolocResponseAdapter::GeolocResponseAdapter(std::stringstream &json_content)
{
	property_tree::read_json(json_content, _root_of_tree);
}

std::string GeolocResponseAdapter::getCountry()
{
	return _root_of_tree.get<std::string>("country");;
}

std::string GeolocResponseAdapter::getRegionName()
{
	return _root_of_tree.get<std::string>("regionName");;
}

std::string GeolocResponseAdapter::getCity()
{
	return _root_of_tree.get<std::string>("city");;
}