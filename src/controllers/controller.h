#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <boost/asio.hpp>
#include <string>
#include "views/view.h"

using boost::asio::ip::tcp;

class RequestController {
public:
    void handle_request(tcp::socket socket);

private:
    std::string parse_request(const std::string& request);
};

#endif // CONTROLLER_H
