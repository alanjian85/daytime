#ifndef DAYTIME_CLIENT_TCP_CLIENT_HPP
#define DAYTIME_CLIENT_TCP_CLIENT_HPP

#include <array>
#include <string_view>

#include <asio.hpp>

namespace daytime {
    namespace client {
        namespace tcp {
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
                void do_connect(asio::ip::tcp::resolver::results_type endpoints);
                void do_read();
            private:
                asio::io_context& io_context_;

                asio::ip::tcp::resolver resolver_;
                asio::ip::tcp::socket socket_;
                std::array<char, 512> buffer_;
            };
        }
    }
}

#endif
