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
	GeolocRequestor(const std::string &providerHostName, const std::string &providerPort, int httpVersionToUse);
	~GeolocRequestor();

	std::string requestGeolocFromIP(const std::string &IPv4);

protected:
	virtual http_request generateGeolocRequest(const std::string &IPv4) = 0;

	const std::string _providerHostName, _providerPort;
	const int _httpVersionToUse;

private:
	void sendRequest(const http_request &geoloc_request);
	http_response readResponse();

	asio::io_context _ioc;
	asio::ip::tcp::resolver _resolver;
	asio::ip::tcp::socket _socket;
};
