#pragma once
//#define _WIN32_WINNT=0x0501

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "GeolocParser.h"
#include "GeolocRequestor.h"
#include "IPtoGeolocConverter.h"