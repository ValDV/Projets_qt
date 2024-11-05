#include "Server.h"
#include <QRandomGenerator>
#include <QString>
#include <QDebug>

Server::Server(QObject* parent) : QObject(parent) {
    connect(&tcpServer, &QTcpServer::newConnection, this, &Server::handleNewConnection);
    if (!tcpServer.listen(QHostAddress::Any, 12345)) {
        qCritical() << "Server could not start!";
    }
    else {
        qDebug() << "Server started on port" << tcpServer.serverPort();
    }
}

void Server::handleNewConnection() {
    QTcpSocket* clientSocket = tcpServer.nextPendingConnection();
    connect(clientSocket, &QTcpSocket::readyRead, this, &Server::readClientRequest);
    connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);
}

void Server::readClientRequest() {
    QTcpSocket* clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) return;

    QByteArray request = clientSocket->readAll();
    QString response;

    if (request.startsWith("Td")) {
        int sensorId = request.mid(2, 2).toInt();
        double temperatureC = -20.00 + static_cast<double>(qrand()) / RAND_MAX * (37.00 - (-20.00));
        response = QString("Td%1,%2%3")
            .arg(sensorId, 2, 10, QChar('0'))
            .arg(temperatureC < 0 ? "-" : "+")
            .arg(qAbs(temperatureC), 0, 'f', 2);
    }
    else if (request.startsWith("Tf")) {
        int sensorId = request.mid(2, 2).toInt();
        double temperatureC = -20.00 + static_cast<double>(qrand()) / RAND_MAX * (37.00 - (-20.00));
        double temperatureF = (temperatureC * 9 / 5) + 32;
        response = QString("Tf%1,%2%3")
            .arg(sensorId, 2, 10, QChar('0'))
            .arg(temperatureF < 0 ? "-" : "+")
            .arg(qAbs(temperatureF), 0, 'f', 2);
    }
    else if (request.startsWith("Hr")) {
        int sensorId = request.mid(2, 2).toInt();
        double humidity = static_cast<double>(qrand()) / RAND_MAX * 99.9;
        response = QString("Hr%1,%2").arg(sensorId, 2, 10, QChar('0')).arg(humidity, 0, 'f', 1);
    }
    else {
        response = "Erreur : Requete invalide";
    }

    clientSocket->write(response.toUtf8());
    clientSocket->flush();
}
