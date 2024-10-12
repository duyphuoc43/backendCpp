#ifndef SERVER_H
#define SERVER_H

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include "controllers/controller.h"

using boost::asio::ip::tcp;

class HttpServer {
public:
    HttpServer(boost::asio::io_context& io_context, short port)
        : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
        start_accept();
    }

private:
    void start_accept() {
        tcp::socket socket(acceptor_.get_io_context());
        acceptor_.async_accept(
            socket,
            [this, &socket](boost::system::error_code ec) {
                if (!ec) {
                    handle_request(std::move(socket));
                }
                start_accept();
            }
        );
    }

    void handle_request(tcp::socket socket) {
        RequestController controller;
        controller.handle_request(std::move(socket));
    }

    tcp::acceptor acceptor_;
};

#endif // SERVER_H
