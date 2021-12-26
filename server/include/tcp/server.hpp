#ifndef DAYTIME_SERVER_TCP_SERVER_HPP
#define DAYTIME_SERVER_TCP_SERVER_HPP

#include <asio.hpp>

#include "connection.hpp"

namespace daytime {
    namespace server {
        namespace tcp {
            class server {
            public:
                server(asio::io_context& io_context) 
                    : io_context_(io_context),
                      acceptor_(io_context, asio::ip::tcp::endpoint(
                                asio::ip::tcp::v4(), 13)),
                      socket_(io_context)
                {
                    do_accept();
                }
            private:
                void do_accept();
            private:
                asio::io_context& io_context_;

                asio::ip::tcp::acceptor acceptor_;
                asio::ip::tcp::socket socket_;
            };
        }
    }
}

#endif
