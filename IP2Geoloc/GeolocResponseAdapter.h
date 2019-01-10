#pragma once
#include "pch.h"

#include <sstream>
#include <string>

namespace property_tree = boost::property_tree;

class GeolocResponseAdapter
{
public:
	GeolocResponseAdapter(std::stringstream &json_content);

	std::string getCountry();
	std::string getRegionName();
	std::string getCity();

private:
	property_tree::ptree _root_of_tree;
};