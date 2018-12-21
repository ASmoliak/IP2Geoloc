int main()
{
	const std::string IPV4_TO_LOOK_UP = "5.29.232.219";
	try
	{
		GeolocationDetailsParser locationParser("sample.json");
		std::cout << locationParser.getCountry() << std::endl;
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