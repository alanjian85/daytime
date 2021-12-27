#include "udp/server.hpp"
using namespace daytime::server::udp;

#include <memory>
#include <string>

#include "utility.hpp"

void server::do_receive() {
    socket_.async_receive_from(asio::buffer(buffer_), endpoint_,
        [this](const asio::error_code& ec, std::size_t) {
            if (!ec) {
                do_send();
            } 

            do_receive();
        });
}

void server::do_send() { 
    auto message = std::make_shared<std::string>(make_daytime_string());
    socket_.async_send_to(asio::buffer(*message), endpoint_,
        [message](const asio::error_code&, std::size_t) {

        });
}
