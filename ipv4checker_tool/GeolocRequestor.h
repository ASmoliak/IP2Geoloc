#pragma once

namespace beast = boost::beast;
namespace http = beast::http;
namespace asio = boost::asio;
namespace ip = asio::ip;
typedef http::request<http::string_body> http_request;


class GeolocRequestor
{
public:
	// C'tor and d'tor
	GeolocRequestor();
	~GeolocRequestor();

	// Public member functions
	beast::flat_buffer resolveToGeoloc(const std::string &IPv4);

private:
	// Private member functions
	http_request generateGeolocRequest(const std::string &IPv4);
	void sendRequest(http_request &geoloc_request);
	beast::flat_buffer readResponse();

	// Private member variables
	asio::io_context _ioc;
	asio::ip::tcp::resolver _resolver;
	asio::ip::tcp::socket _socket;

	// Constants
	static constexpr const char *HOST = "www.ip-api.com";
	static constexpr const char *PORT = "80";
	static constexpr int VERSION = 11;
};