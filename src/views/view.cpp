#include "view.h"

std::string View::create_response(const std::string& message) {
    std::string http_response = "HTTP/1.1 200 OK\r\n";
    http_response += "Content-Length: " + std::to_string(message.size()) + "\r\n";
    http_response += "Content-Type: text/plain\r\n";
    http_response += "Connection: close\r\n";
    http_response += "\r\n";
    http_response += message;
    return http_response;
}
