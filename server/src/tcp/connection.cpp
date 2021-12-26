#include "tcp/connection.hpp"
using namespace daytime::server::tcp;

#include "utility.hpp"

void connection::start() {
    message_ = make_daytime_string();
    auto self = shared_from_this();
    asio::async_write(socket_, asio::buffer(message_),
        [self](const asio::error_code&, std::size_t) {

        });
}
