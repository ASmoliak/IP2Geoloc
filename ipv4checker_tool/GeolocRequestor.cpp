GeolocRequestor::GeolocRequestor() :
	_ioc(), _socket(_ioc), _resolver(_ioc)
{ 
}

GeolocRequestor::~GeolocRequestor()
{
	boost::system::error_code errorcode;
	_socket.shutdown(ip::tcp::socket::shutdown_both, errorcode);
}

beast::flat_buffer GeolocRequestor::resolveToGeoloc(const std::string &IPv4)
{
	http_request resolve_request = generateGeolocRequest(IPv4);
	sendRequest(resolve_request);
	return readResponse();
}

http_request GeolocRequestor::generateGeolocRequest(const std::string &IPv4)
{
	std::string target_url = "/json/" + IPv4;
	http_request request{ http::verb::get, target_url, VERSION };
	request.set(http::field::host, HOST);
	request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

	return request;
}

void GeolocRequestor::sendRequest(http_request &geoloc_request)
{
	auto const results = _resolver.resolve(HOST, PORT);

	asio::connect(_socket, results.begin(), results.end());
	http::write(_socket, geoloc_request);
}

beast::flat_buffer GeolocRequestor::readResponse()
{
	beast::flat_buffer buffer;
	http::response<http::dynamic_body> response;
	http::read(_socket, buffer, response);

	return buffer;
}

