ComplexPathGetter::ComplexPathGetter(std::stringstream json_content) :
	_complex_path_value(-1)
{
	property_tree::read_json(json_content, _root_of_tree);
}

ComplexPathGetter::ComplexPathGetter(const std::string& json_file_name) :
	_complex_path_value(-1)
{
	property_tree::read_json(json_file_name, _root_of_tree);
}

int ComplexPathGetter::getComplexPathValue()
{
	if (_complex_path_value == -1)
	{
		readComplexPathValue();
	}
	return _complex_path_value;
}

void ComplexPathGetter::readComplexPathValue()
{
	_complex_path_value = _root_of_tree.get<int>("height");
}