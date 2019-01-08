#pragma once
#include "pch.h"

#include <sstream>
#include <string>

namespace property_tree = boost::property_tree;

class GeolocResponseAdapter
{
public:
	// C'tor and D'tor
	GeolocResponseAdapter(std::stringstream &json_content);
	GeolocResponseAdapter(const std::string &json_file_name);

	// Public member functions
	std::string getCountry();
	std::string getRegionName();
	std::string getCity();

private:
	// Member variables
	property_tree::ptree _root_of_tree;
};