#include "tcp/client.hpp"
#include <cmath>
using namespace daytime::client::tcp;

#include <array>
#include <iostream>
#include <stdexcept>

void client::run(std::string_view host) {
    auto endpoints = resolver_.resolve(host, "daytime");
    asio::connect(socket_, endpoints);

    for (;;) {
        std::array<char, 128> buffer;
        asio::error_code ec;

        auto length = socket_.read_some(asio::buffer(buffer), ec);
        if (ec == asio::error::eof)
            break;
        else if (ec)
            throw std::system_error(ec);
    
        std::cout.write(buffer.data(), length);
    }
}
