#include "tcp/server.hpp"
using namespace daytime::server::tcp;

#include "tcp/connection.hpp"

void server::do_accept() {
    auto new_connection = connection::create(io_context_);
    acceptor_.async_accept(new_connection->socket(),
        [this, new_connection](const asio::error_code& ec) {
            if (!ec) {
                new_connection->start();
            }

            do_accept();
        });
}
