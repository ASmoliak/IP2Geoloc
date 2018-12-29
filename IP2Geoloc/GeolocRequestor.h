#pragma once

namespace beast = boost::beast;
namespace http = beast::http;
namespace asio = boost::asio;
typedef http::request<http::string_body> http_request;
typedef http::response<http::dynamic_body> http_response;

class GeolocRequestor
{
public:
	// C'tor and d'tor
	GeolocRequestor();
	~GeolocRequestor();

	// Public member functions
	std::string requestGeolocFromIP(const std::string &IPv4);

private:
	// Private member functions
	http_request generateGeolocRequest(const std::string &IPv4);
	void sendRequest(const http_request &geoloc_request);
	http_response readResponse();

	// Private member variables
	asio::io_context _ioc;
	asio::ip::tcp::resolver _resolver;
	asio::ip::tcp::socket _socket;

	// Constants
	static constexpr const char *HOST = "www.ip-api.com";
	static constexpr const char *PORT = "80";
	static constexpr int VERSION = 11;
};