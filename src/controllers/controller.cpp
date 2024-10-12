#include "controller.h"

void RequestController::handle_request(tcp::socket socket) {
    char buffer[1024];
    boost::system::error_code error;

    // Đọc yêu cầu từ client
    size_t len = socket.read_some(boost::asio::buffer(buffer), error);
    if (!error) {
        std::string request(buffer, len);
        std::string response_message = parse_request(request);

        ResponseView response_view;
        std::string response = response_view.create_response(response_message);
        
        // Gửi phản hồi lại cho client
        boost::asio::write(socket, boost::asio::buffer(response), error);
    }
}

std::string RequestController::parse_request(const std::string& request) {
    // Xử lý yêu cầu (có thể thêm logic ở đây)
    return "Hello from MVC server!";
}
