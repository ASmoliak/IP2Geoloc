#pragma once
#include <string>

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/noncopyable.hpp>

class GeolocRequestor : boost::noncopyable
{
	static constexpr auto HOST = "www.ip-api.com";
	static constexpr auto PORT = "80";
	static constexpr auto HTTP_VERSION = 11;

	typedef boost::beast::http::request<boost::beast::http::string_body> http_request;
	typedef boost::beast::http::response<boost::beast::http::dynamic_body> http_response;

	boost::asio::io_context _ioc;
	boost::asio::ip::tcp::socket _socket;
	boost::asio::ip::tcp::resolver _resolver;

public:
	GeolocRequestor() :
		_socket(_ioc),
		_resolver(_ioc)
	{
	}

	std::string requestGeoloc(const std::string& IPv4)
	{
		sendRequest(buildRequest(IPv4));

		auto raw_response = readResponse();
		return boost::beast::buffers_to_string(raw_response.body().data());
	}

private:
	http_request buildRequest(const std::string& IPv4) const
	{
		std::string target_url = "/json/" + IPv4;

		http_request request{ boost::beast::http::verb::get, target_url, HTTP_VERSION };
		request.set(boost::beast::http::field::host, HOST);
		request.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		return request;
	}

	void sendRequest(const http_request& geoloc_request)
	{
		const auto target_hosts = _resolver.resolve(HOST, PORT);

		boost::asio::connect(_socket, target_hosts.begin(), target_hosts.end());
		boost::beast::http::write(_socket, geoloc_request);
	}

	http_response readResponse()
	{
		boost::beast::flat_buffer buffer;
		http_response response;
		boost::beast::http::read(_socket, buffer, response);

		return response;
	}
};