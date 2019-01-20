#include "pch.h"

#include <string>
#include <iostream>
#include <sstream>

#include "GeolocCSVResponseAdapter.h"

GeolocCSVResponseAdapter::GeolocCSVResponseAdapter(const std::string &InputCSVData)
{
	_tokens = getTokensFromCSV(InputCSVData);
}

std::vector<std::string> GeolocCSVResponseAdapter::getTokensFromCSV(const std::string &InputCSVData)
{
	std::vector<std::string> result;

	std::istringstream lineStream(InputCSVData);
	std::string cell;

	while (std::getline(lineStream, cell, ';'))
	{
		result.push_back(cell);
	}
	// This checks for a trailing comma with no data after it.
	if (!lineStream && cell.empty())
	{
		result.push_back("");
	}
	return result;
}
