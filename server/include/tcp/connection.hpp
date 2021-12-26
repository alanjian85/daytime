#ifndef DAYTIME_SERVER_TCP_CONNECTION_HPP
#define DAYTIME_SERVER_TCP_CONNECTION_HPP

#include <string>
#include <memory>

#include <asio.hpp>

namespace daytime {
    namespace server {
        namespace tcp {
            class connection : public std::enable_shared_from_this<connection> {
            public:
                static auto create(asio::io_context& io_context) {
                    return std::shared_ptr<connection>(new connection(io_context)); 
                }

                auto& socket() const noexcept {
                    return socket_;
                }

                auto& socket() noexcept {
                    return socket_;
                }

                void start();
            private:
                connection(asio::io_context& io_context) 
                    : socket_(io_context)
                {
                    
                }
            private:
                asio::ip::tcp::socket socket_;
                std::string message_;
            };
        }
    }
}

#endif
