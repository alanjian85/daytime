#include "client.hpp"
using namespace daytime::client::udp;

#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: daytime_client_udp <host>\n";
        return 1;
    }

    asio::io_context io_context;

    client c(io_context, argv[1]);

    io_context.run();
    return 0;
}
