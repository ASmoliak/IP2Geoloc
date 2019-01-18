#include "pch.h"

#include <sstream>
#include <string>

#include "GeolocJSONResponseAdapter.h"

GeolocJSONResponseAdapter::GeolocJSONResponseAdapter(std::stringstream &json_content)
{
	property_tree::read_json(json_content, _root_of_tree);
}
