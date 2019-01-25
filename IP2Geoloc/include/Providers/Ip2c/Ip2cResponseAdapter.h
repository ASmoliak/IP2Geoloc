#pragma once
#include "pch.h"

#include "GeolocCSVResponseAdapter.h"
#include "Ip2cResponseAdapter.h"

// TODO add a CSV Parser
// TODO solve the Geolocation missing data issue
// TODO add config file
// TODO add provider setting in config file
class Ip2cResponseAdapter : GeolocCSVResponseAdapter
{
public:
	Ip2cResponseAdapter(const std::string &inputCSV);

	std::string getCountry();

private:
	static enum IndexNames
	{
		ResponseStatus,
		TwoLetterCountryName,
		ThreeLetterCountryName,
		FullCountryName
	};

	static constexpr auto RESPONSE_STATUS_FAILED = "0";
	static constexpr auto RESPONSE_STATUS_SUCCESS = "1";
	static constexpr auto RESPONSE_STATUS_CANNOT_FIND = "2";
};