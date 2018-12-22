#include "GeolocRequestor.h"
#include "GeolocParser.h"

GeolocRequestor::GeolocRequestor() :
	_ioc(), _socket(_ioc), _resolver(_ioc)
{ 
}

GeolocRequestor::~GeolocRequestor()
{
	boost::system::error_code errorcode;
	_socket.shutdown(asio::ip::tcp::socket::shutdown_both, errorcode);
}

std::string GeolocRequestor::requestGeolocFromIP(const std::string &IPv4)
{
	http_request resolve_request = generateGeolocRequest(IPv4);
	sendRequest(resolve_request);

	http_response resolve_response = readResponse();
	std::string response_body = beast::buffers_to_string(resolve_response.body().data());
	return response_body;
}

http_request GeolocRequestor::generateGeolocRequest(const std::string &IPv4)
{
	std::string target_url = "/json/" + IPv4;
	http_request request{ http::verb::get, target_url, VERSION };
	request.set(http::field::host, HOST);
	request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

	return request;
}

void GeolocRequestor::sendRequest(const http_request &geoloc_request)
{
	auto const results = _resolver.resolve(HOST, PORT);

	asio::connect(_socket, results.begin(), results.end());
	http::write(_socket, geoloc_request);
}

http_response GeolocRequestor::readResponse()
{
	beast::flat_buffer buffer;
	http_response response;
	http::read(_socket, buffer, response);

	return response;
}

