#include "client.hpp"
using namespace daytime::client::tcp;

#include <iostream>

void client::do_resolve(std::string_view host) {
    resolver_.async_resolve(host, "daytime",
        [this](const asio::error_code& ec, auto endpoints) {
            do_connect(endpoints);
        });
}

void client::do_connect(asio::ip::tcp::resolver::results_type endpoints) {
    asio::async_connect(socket_, endpoints,
        [this](const asio::error_code& ec, const asio::ip::tcp::endpoint&) {
            if (!ec) {
                do_read();
            }
        });
}

void client::do_read() {
    asio::async_read(socket_, asio::buffer(buffer_),
        [this](const asio::error_code& ec, std::size_t bytes_transferred) {
            if (!ec || ec == asio::error::eof) {
                std::cout.write(buffer_.data(), bytes_transferred); 
            }
        });
}
