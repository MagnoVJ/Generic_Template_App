#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QTcpSocket>
#include <QCoreApplication>
#include <QDebug>

#include "interface_helper.hpp"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    InterfaceHelper interfaceHelper;

    engine.rootContext()->setContextProperty("interfaceHelper", &interfaceHelper);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    //IPC
    //QTcpSocket socket;

    // Connect to server
    //socket.connectToHost("127.0.0.1", 12345); // IP and port of server

    //if(!socket.waitForConnected(3000)) {
    //    qDebug() << "Connection failed!";
    //}
    //else
    //  qDebug() << "Connected to server.";

    // Send message
    //socket.write("Hello from Qt client!");
    //socket.waitForBytesWritten(1000);

    // Read response
    //socket.waitForReadyRead(3000);
    //qDebug() << "Server says: " << socket.readAll();

    //socket.disconnectFromHost();

    return app.exec();
}
