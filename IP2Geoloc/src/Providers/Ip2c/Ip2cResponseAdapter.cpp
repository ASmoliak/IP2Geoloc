#include "pch.h"

#include "GeolocCSVResponseAdapter.h"
#include "Ip2cResponseAdapter.h"

// TODO solve the Geolocation missing data issue
// TODO add config file
// TODO add provider setting in config file

Ip2cResponseAdapter::Ip2cResponseAdapter(const std::string &inputCSV) :
	GeolocCSVResponseAdapter(inputCSV)
{
}

std::string Ip2cResponseAdapter::getCountry()
{
	if (_tokens.at(IndexNames::ResponseStatus) == RESPONSE_STATUS_SUCCESS)
	{
		return _tokens.at(IndexNames::FullCountryName);
	}
	else
	{
		return "N/A";
	}
}