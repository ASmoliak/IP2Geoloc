#include "pch.h"

#include <string>

#include "GeolocRequestor.h"
#include "GeolocJSONResponseAdapter.h"

GeolocRequestor::GeolocRequestor(const std::string &providerHostName, const std::string &providerPort, int httpVersionToUse) :
	_ioc(), _socket(_ioc), _resolver(_ioc), 
	_providerHostName(providerHostName), _providerPort(providerPort), _httpVersionToUse(httpVersionToUse)
{
}

GeolocRequestor::~GeolocRequestor()
{
	boost::system::error_code error_code;
	_socket.shutdown(asio::ip::tcp::socket::shutdown_both, error_code);
}

std::string GeolocRequestor::requestGeoloctionOfIPV4(const std::string &IPv4)
{
	http_request resolve_request = generateGeolocRequest(IPv4);
	sendRequest(resolve_request);

	http_response resolve_response = readResponse();
	std::string response_body = beast::buffers_to_string(resolve_response.body().data());
	return response_body;
}

void GeolocRequestor::sendRequest(const http_request &geoloc_request)
{
	auto const results = _resolver.resolve(_providerHostName, _providerPort);

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
