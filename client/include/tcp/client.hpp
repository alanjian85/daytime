#ifndef DAYTIME_CLIENT_TCP_CLIENT_HPP
#define DAYTIME_CLIENT_TCP_CLIENT_HPP

#include <string_view>

#include <asio.hpp>

namespace daytime {
    namespace client {
        namespace tcp {
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

                asio::ip::tcp::resolver resolver_;
                asio::ip::tcp::socket socket_;
            };
        }
    }
}

#endif
