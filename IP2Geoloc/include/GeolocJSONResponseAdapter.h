#pragma once
#include "pch.h"

#include <sstream>
#include <string>

namespace property_tree = boost::property_tree;

class GeolocJSONResponseAdapter
{
public:
	GeolocJSONResponseAdapter(std::stringstream &json_content);

protected:
	property_tree::ptree _root_of_tree;
};
