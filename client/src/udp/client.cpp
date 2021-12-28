#include "udp/client.hpp"
using namespace daytime::client::udp;

#include <array>
#include <iostream>

void client::run(std::string_view host) {
    auto send_endpoint = *resolver_.resolve(asio::ip::udp::v4(), host, "daytime").cbegin();
    socket_.open(asio::ip::udp::v4());

    std::array<char, 1> send_buffer = {'\0'};
    socket_.send_to(asio::buffer(send_buffer), send_endpoint);

    std::array<char, 128> recv_buffer;
    asio::ip::udp::endpoint recv_endpoint;
    auto length = socket_.receive_from(asio::buffer(recv_buffer), recv_endpoint);

    std::cout.write(recv_buffer.data(), length);
}
