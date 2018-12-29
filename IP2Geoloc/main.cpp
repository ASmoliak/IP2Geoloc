#include "pch.h"

#include <iostream>

#include "ProgramArgumentsParser.h"
#include "IPtoGeolocConverter.h"

Settings _global_settings;

namespace property_tree = boost::property_tree;

void runGeolocationResolver()
{
	try
	{
		IPtoGeolocConverter converter;
		Geolocation result = converter.convertIPtoGeoloc(_global_settings.IPv4_to_scan);
		result.printFields();
	}
	catch (const property_tree::file_parser_error &e)
	{
		std::cout << "<CRITICAL>" << e.what() << std::endl;
	}
	catch (const property_tree::ptree_bad_path &e)
	{
		std::cout << "<CRITICAL>" << e.what() << std::endl;
	}
	catch (const property_tree::ptree_error &e)
	{
		std::cout << "<CRITICAL> ptree error: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "<CRITICAL> Unknown exception." << std::endl;
	}
}

int main(int argc, char *argv[])
{
	try
	{
		ProgramArgumentsParser argument_parser(argc, argv);
		_global_settings = argument_parser.getParsedSettings();
		runGeolocationResolver();
	}
	catch (const boost::program_options::error &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}