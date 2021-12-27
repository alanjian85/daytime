#include "client.hpp"
using namespace daytime::client::udp;

#include <iostream>

void client::do_resolve(std::string_view host) {
    resolver_.async_resolve(host, "daytime",
        [this](const asio::error_code& ec, auto endpoints) {
            if (!ec) {
                do_receive(*endpoints);
            }
        });
}

void client::do_receive(asio::ip::udp::endpoint endpoint) {
    socket_.async_receive_from(asio::buffer(buffer_), endpoint,
        [this](const asio::error_code& ec, std::size_t bytes_transferred) {
            if (!ec || ec == asio::error::eof) {
                std::cout.write(buffer_.data(), bytes_transferred);
            }
        });
}
