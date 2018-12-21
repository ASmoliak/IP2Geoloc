#pragma once

namespace property_tree = boost::property_tree;

class GeolocationDetailsParser
{
public:
	// C'tor and D'tor
	GeolocationDetailsParser(std::stringstream json_content);
	GeolocationDetailsParser(const std::string& json_file_name);

	// Public member functions
	std::string getCountry();
	std::string getRegionName();
	std::string getCity();

private:
	// Private Member functions
	void readGeolocationInfo();

	// Member variables
	property_tree::ptree _root_of_tree;
	std::string _country, _regionName, _city;
};