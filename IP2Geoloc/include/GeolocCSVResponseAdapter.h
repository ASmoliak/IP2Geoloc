#pragma once
#include "pch.h"

#include <string>
#include <sstream>

class GeolocCSVResponseAdapter
{
public:
	GeolocCSVResponseAdapter(const std::string &InputCSVData);

protected:
	std::vector<std::string> getTokensFromCSV(const std::string &InputCSVData);


	std::vector<std::string> _tokens;
};