#pragma once

namespace property_tree = boost::property_tree;

class ComplexPathGetter
{
public:
	// C'tor and D'tor
	ComplexPathGetter(std::stringstream json_content);
	ComplexPathGetter(const std::string& json_file_name);
	int getComplexPathValue();

private:
	// Private Member functions
	void readComplexPathValue();

	// Member variables
	property_tree::ptree _root_of_tree;
	int _complex_path_value;
};