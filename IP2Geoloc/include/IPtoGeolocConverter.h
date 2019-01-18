#pragma once
#include "pch.h"

#include <string>

#include "Geolocation.h"


class IPtoGeolocConverter
{
public:
	static Geolocation resolveIPtoGeoloc(const std::string &IPv4 = "");

private:
	static void validateIP(const std::string &IPv4_address);
};
