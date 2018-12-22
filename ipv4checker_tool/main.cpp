std::string getUserInputIP()
{
	std::string IPv4;

	do
	{
		std::cout << "Enter an IPv4 address to resolve geolocation for: ";
		std::cin >> IPv4;

		boost::system::error_code ec;
		asio::ip::address::from_string(IPv4, ec);
		if (ec)
		{
			std::cout << "Input IPv4 is invalid" << std::endl;
			continue;
		}
		else
		{
			return IPv4;
		}
	} while (1);
}

int main()
{
	try
	{
		for (;;)
		{
			std::string IPv4 = getUserInputIP();
			IPtoGeolocConverter converter;
			Geolocation result = converter.convertIPtoGeoloc(IPv4);
			result.print();
		}
	}
	catch (const property_tree::file_parser_error &e)
	{
		std::cout << "JSON Content is invalid: " << e.what() << std::endl;
	}
	catch (const property_tree::ptree_bad_path &e)
	{
		std::cout << "JSON path not valid: " << e.what() << std::endl;
	}
	catch (const property_tree::ptree_error &e)
	{
		std::cout << "ptree error: " << e.what() << std::endl;
	}
	return 0;
}