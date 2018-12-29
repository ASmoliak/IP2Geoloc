#include "pch.h"

#include <iostream>

#include "ProgramArgumentsParser.h"
#include "IPtoGeolocConverter.h"

Settings globalSettings;

namespace property_tree = boost::property_tree;

void runGeolocationResolver()
{
	try
	{
		IPtoGeolocConverter converter;
		Geolocation result = converter.convertIPtoGeoloc(globalSettings.IPv4_to_scan);
		result.print();
	}
	catch (const property_tree::file_parser_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const property_tree::ptree_bad_path &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const property_tree::ptree_error &e)
	{
		std::cout << "ptree error: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown exception..." << std::endl;
	}
}

int main(int argc, char *argv[])
{
	try
	{
		ProgramArgumentsParser argument_parser(argc, argv);
		globalSettings = argument_parser.getParsedSettings();
		runGeolocationResolver();
	}
	catch (const boost::program_options::error &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}