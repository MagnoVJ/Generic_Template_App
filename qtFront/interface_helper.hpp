#ifndef INTERFACE_HELPER_HPP
#define INTERFACE_HELPER_HPP

#include <QTcpSocket>
#include <QObject>
#include <QString>
#include <QDebug>

class InterfaceHelper : public QObject {

    Q_OBJECT

public:
    explicit InterfaceHelper(QObject* parent = nullptr) : QObject(parent) { }

    Q_INVOKABLE void processInput(const QString& first, const QString& second);
    Q_INVOKABLE void windowClosing();

};

#endif // INTERFACE_HELPER_HPP
