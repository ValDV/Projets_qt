#include "InitiationQt.h"

InitiationQt::InitiationQt(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    socket = new QTcpSocket(this);
    QObject::connect(socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
    QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));

    server = new QTcpServer(this);
    QObject::connect(server, SIGNAL(newConnection()), this, SLOT(onServerNewConnection()));
    server->listen(QHostAddress::AnyIPv4, 4321);
}

InitiationQt::~InitiationQt()
{}

void InitiationQt::onDisplayMessageButtonClicked()
{
    ui.label->setText("Hello world !");
}

void InitiationQt::onConnectButtonClicked()
{
    QString ip = ui.IPLineEdit->text();
    QString port = ui.portLineEdit->text();

    bool ok;
    int portAsInt = port.toInt(&ok);
    if (ok)
    {
        socket->connectToHost(ip, portAsInt);
    }
}

void InitiationQt::onSocketConnected()
{
    ui.connectionStatusLabel->setText("Status connexion : Connecté");
}

void InitiationQt::onSocketDisconnected()
{
    ui.connectionStatusLabel->setText("Status connexion : Déconnecté");
}

void InitiationQt::onSendMessageButtonClicked()
{
    if (socket->state() == QTcpSocket::ConnectedState)
    {
        socket->write("Hello server !\n");
    }
}

void InitiationQt::onSocketReadyRead()
{
    QByteArray data = socket->read(socket->bytesAvailable());
    QString str(data);
    ui.connectionStatusLabel->setText("Status connexion : Message reçu =" + str);
}

void InitiationQt::onServerNewConnection()
{
    ui.connectionStatusLabel->setText("Un client s'est connecté");
    QTcpSocket* client = server->nextPendingConnection();
    QObject::connect(client, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
    QObject::connect(client, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));
}

void InitiationQt::onClientDisconnected()
{
    QTcpSocket* obj = qobject_cast<QTcpSocket*>(sender());
    QObject::disconnect(obj, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
    QObject::disconnect(obj, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));
    obj->deleteLater();
}

void InitiationQt::onClientReadyRead()
{
    QTcpSocket* obj = qobject_cast<QTcpSocket*>(sender());
    QByteArray data = obj->read(obj->bytesAvailable());
    QString str(data);
    ui.connectionStatusLabel->setText("Status connexion : Message reçu =" + str);
    obj->write(data);
}
