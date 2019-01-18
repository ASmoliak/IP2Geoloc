#pragma once
#include "pch.h"

#include "GeolocJSONResponseAdapter.h"

class IpApiResponseAdapter : public GeolocJSONResponseAdapter
{
public:
	IpApiResponseAdapter(std::stringstream &raw_response_in_json);

	std::string getCountry();
	std::string getRegionName();
	std::string getCity();
};
