#ifndef DAYTIME_SERVER_UDP_SERVER_HPP
#define DAYTIME_SERVER_UDP_SERVER_HPP

#include <array>

#include <asio.hpp>

namespace daytime {
    namespace server {
        namespace udp {
            class server {
            public:
                server(asio::io_context& io_context) 
                    : io_context_(io_context),
                      socket_(io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), 13))
                {
                    do_receive();
                }
            private:
                void do_receive();
                void do_send();
            private:
                asio::io_context& io_context_;

                asio::ip::udp::socket socket_;
                asio::ip::udp::endpoint endpoint_;
                std::array<char, 1> buffer_;
            };
        }
    }
}

#endif
