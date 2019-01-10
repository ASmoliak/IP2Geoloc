#pragma once
#include "pch.h"

#include <string>

namespace beast = boost::beast;
namespace http = beast::http;
namespace asio = boost::asio;
typedef http::request<http::string_body> http_request;
typedef http::response<http::dynamic_body> http_response;

class GeolocRequestor
{
public:
	GeolocRequestor();
	~GeolocRequestor();

	std::string requestGeolocFromIP(const std::string &IPv4);

private:
	http_request generateGeolocRequest(const std::string &IPv4);
	void sendRequest(const http_request &geoloc_request);
	http_response readResponse();

	static constexpr const char *HOST = "www.ip-api.com";
	static constexpr const char *PORT = "80";
	static constexpr int HTTP_VERSION = 11;

	asio::io_context _ioc;
	asio::ip::tcp::resolver _resolver;
	asio::ip::tcp::socket _socket;
};