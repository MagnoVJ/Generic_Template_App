#include "interface_helper.hpp"

Q_INVOKABLE void InterfaceHelper::processInput(const QString& first, const QString& second) {

    QTcpSocket socket;

    socket.connectToHost("127.0.0.1", 12345); // IP and port of server

    if(!socket.waitForConnected(3000)) {
        qDebug() << "Connection failed!";
    }
    else
        qDebug() << "Connected to server.";

    // This & serves to separate the first string of the line edit with the second string
    QString firstBuff = first + '&';

    const char* firstCChar = firstBuff.toUtf8().constData();
    const char* secondCChar = second.toUtf8().constData();

    socket.write(firstCChar);
    socket.write(secondCChar);

    socket.waitForBytesWritten(1000);

    socket.disconnectFromHost();

}

Q_INVOKABLE void InterfaceHelper::windowClosing() {

    QTcpSocket socket;

    socket.connectToHost("127.0.0.1", 12345); // IP and port of server

    if(!socket.waitForConnected(3000)) {
        qDebug() << "Connection failed!";
    }
    else
        qDebug() << "Connected to server.";

    QString cc = "close_connection";

    socket.write(cc.toUtf8().constData());

    socket.waitForBytesWritten(1000);

    socket.disconnectFromHost();

}
