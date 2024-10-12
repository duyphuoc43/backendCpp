#include <QGuiApplication>
#include <QQmlApplicationEngine>
// #include "main.h"
using namespace std;
int main(int argc, char *argv[])
{
    // View::UI ui;
    // Model::Storage storage;

    // // Tạo đối tượng của Controller và truyền View và Model vào
    // Controller::Logic logic(&ui, &storage);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    try {
        boost::asio::io_context io_context;
        HttpServer server(io_context, 8080);
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("cpp-be", "Main");


    return app.exec();
}
