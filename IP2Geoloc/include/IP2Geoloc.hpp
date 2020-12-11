#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "GeolocRequestor.hpp"

class IP2Geoloc : boost::noncopyable
{
	GeolocRequestor requestor;

public:
	struct Geolocation
	{
		std::string _country, _region_name, _city;

		Geolocation() = default;
		Geolocation(std::string country, std::string region_name, std::string city) :
			_country(std::move(country)),
			_region_name(std::move(region_name)),
			_city(std::move(city))
		{
		}

		void print()
		{
			std::cout << "Country: " << _country << std::endl;
			std::cout << "Region: " << _region_name << std::endl;
			std::cout << "City: " << _city << std::endl;
		}

		bool operator==(const Geolocation& other)
		{
			return (_country == other._country &&
				_region_name == other._region_name &&
				_city == other._city);
		}
	};

	Geolocation resolve(const std::string& IPv4 = "")
	{
		if (!isValidIPv4(IPv4))
		{
			throw std::invalid_argument("Input IPv4 address is invalid");
		}

		std::stringstream geoloc_in_json;
		geoloc_in_json << requestor.requestGeoloc(IPv4);

		boost::property_tree::ptree _root_of_tree;
		boost::property_tree::read_json(geoloc_in_json, _root_of_tree);

		return Geolocation(
			_root_of_tree.get<std::string>("country"),
			_root_of_tree.get<std::string>("regionName"),
			_root_of_tree.get<std::string>("city"));
	}

private:
	static bool isValidIPv4(const std::string& IPv4)
	{
		boost::system::error_code ec;
		auto raw_ipv4_address = boost::asio::ip::address::from_string(IPv4, ec);

		return (!ec && raw_ipv4_address.to_string() == IPv4);
	}
};