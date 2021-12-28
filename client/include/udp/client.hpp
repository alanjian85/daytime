#ifndef DAYTIME_CLIENT_UDP_CLIENT_HPP
#define DAYTIME_CLIENT_UDP_CLIENT_HPP

#include <asio.hpp>

#include <string_view>

namespace daytime {
    namespace client {
        namespace udp {
            class client {
            public:
                client()
                    : resolver_(io_context_),
                      socket_(io_context_)
                {
                
                }

                void run(std::string_view host);
            private:
                asio::io_context io_context_;

                asio::ip::udp::resolver resolver_;
                asio::ip::udp::socket socket_;
            };
        }
    }
}

#endif
