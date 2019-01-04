#pragma once
#include "pch.h"

#include <iostream>
#include <string>

#include "GeolocRequestor.h"

struct Geolocation
{
	// Member variables
	std::string _country;
	std::string _region_name;
	std::string _city;

	// C'tor
	Geolocation(const std::string &country, const std::string &region_name, const std::string &city) :
		_country(country), _region_name(region_name), _city(city)
	{
	}

	// Public member functions
	void printFields()
	{
		std::cout << "Country: " << _country << std::endl;
		std::cout << "Region: " << _region_name << std::endl;
		std::cout << "City: " << _city << std::endl;
	}

	bool operator==(const Geolocation &other)
	{
		bool equals = true;
		equals &= _country != other._country;
		equals &= _region_name != other._region_name;
		equals &= _city != other._city;
		return equals;
	}
};

class IPtoGeolocConverter
{
public:
	// Public member functions
	static Geolocation convertIPtoGeoloc(const std::string &IPv4);
};
