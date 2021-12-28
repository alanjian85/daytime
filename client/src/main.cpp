#include <iostream>
#include <stdexcept>
#include <string_view>

#include "tcp/client.hpp"
#include "udp/client.hpp"
using namespace daytime::client;

int main(int argc, char* argv[]) {
    try {
        if (argc < 1) {
            std::cerr << "Usage: daytime_client <host> [-u]\n";
            return 1;
        }

        bool use_udp = false;
        for (auto i = 1; i < argc; ++i) {
            if (std::string_view(argv[0]) == "-u") {
                use_udp = true;
            }
        }

        if (!use_udp) {
            tcp::client c;
            c.run(argv[1]);
        } else {
            udp::client c;
            c.run(argv[1]);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 0;
    }

    return 0;
}
