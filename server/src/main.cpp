#include "tcp/server.hpp"
using namespace daytime::server;

int main() {
    asio::io_context io_context;

    tcp::server tcp_server(io_context);

    io_context.run();
    return 0;
}
