#pragma once
#include "pch.h"

#include <iostream>
#include <string>

#include "GeolocRequestor.h"

struct Geolocation
{
	// Member variables
	std::string _country;
	std::string _regionName;
	std::string _city;
	
	// C'tor
	Geolocation(const std::string& country, const std::string& regionName, const std::string& city) :
		_country(country), _regionName(regionName), _city(city)
	{
	}

	// Public member functions
	void print()
	{
		std::cout << "Country: " << _country << std::endl;
		std::cout << "Region: " << _regionName << std::endl;
		std::cout << "City: " << _city << std::endl;
	}
};

class IPtoGeolocConverter
{
public:
	// c'tors and d'tors
	IPtoGeolocConverter();
	~IPtoGeolocConverter();

	// Public member functions
	Geolocation convertIPtoGeoloc(const std::string& IPv4);
private:

	// Member variables
	GeolocRequestor _requestor;
};
