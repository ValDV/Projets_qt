#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>

class Server : public QObject {
    Q_OBJECT
public:
    explicit Server(QObject* parent = nullptr);

private slots:
    void handleNewConnection();
    void readClientRequest();

private:
    QTcpServer tcpServer;
};

#endif
