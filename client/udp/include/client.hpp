#ifndef DAYTIME_CLIENT_UDP_CLIENT_HPP
#define DAYTIME_CLIENT_UDP_CLIENT_HPP

#include <array>
#include <string_view>

#include <asio.hpp>

namespace daytime {
    namespace client {
        namespace udp {
            class client {
            public:
                client(asio::io_context& io_context, std::string_view host)
                    : io_context_(io_context),
                      resolver_(io_context),
                      socket_(io_context)
                {
                    do_resolve(host);
                }
            private:
                void do_resolve(std::string_view host);
                void do_receive(asio::ip::udp::endpoint endpoint);
            private:
                asio::io_context& io_context_;
                
                asio::ip::udp::resolver resolver_;
                asio::ip::udp::socket socket_;
                std::array<char, 512> buffer_;
            };
        }
    }
}

#endif
