#include "pch.h"

#include "IpApiResponseAdapter.h"

IpApiResponseAdapter::IpApiResponseAdapter(std::stringstream &raw_response_in_json) :
	GeolocJSONResponseAdapter(raw_response_in_json)
{
}

std::string IpApiResponseAdapter::getCountry()
{
	return _root_of_tree.get<std::string>("country");
}

std::string IpApiResponseAdapter::getRegionName()
{
	return _root_of_tree.get<std::string>("regionName");
}

std::string IpApiResponseAdapter::getCity()
{
	return _root_of_tree.get<std::string>("city");
}
