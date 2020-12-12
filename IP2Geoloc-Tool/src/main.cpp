#include <iostream>

#include "ArgumentParser.hpp"
#include "IP2Geoloc.hpp"

Settings _global_settings;

void runGeolocationResolver()
{
	IP2Geoloc ip2geoloc;
	IP2Geoloc::Geolocation result;
	if (_global_settings.resolve_self)
	{
		result = ip2geoloc.resolve();
	}
	else
	{
		result = ip2geoloc.resolve(_global_settings.IPv4_to_scan);
	}

	result.print();
}

int main(int argc, char* argv[])
{
	try
	{
		ArgumentParser argument_parser(argc, (const char**)argv);
		_global_settings = argument_parser.getParsedSettings();
		runGeolocationResolver();
	}
	catch (const std::exception& e)
	{
		std::cout << "<CRITICAL> " << e.what() << std::endl;
	}

	return 0;
}