#include "Client.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QHostAddress>

Client::Client(QWidget* parent)
    : QWidget(parent), socket(new QTcpSocket(this)) {

    ipLineEdit = new QLineEdit("127.0.0.1", this);
    portLineEdit = new QLineEdit("12345", this);

    connectButton = new QPushButton("Connecter", this);
    disconnectButton = new QPushButton("Deconnecter", this);
    disconnectButton->setEnabled(false);

    statusLabel = new QLabel("Statut : Non connecte", this);
    responseLabel = new QLabel(this);

    requestComboBox = new QComboBox(this);
    requestComboBox->addItem("Td01?");
    requestComboBox->addItem("Tf01?");
    requestComboBox->addItem("Hr01?");
    QPushButton* sendRequestButton = new QPushButton("Envoyer requete", this);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new QLabel("Adresse IP :"));
    mainLayout->addWidget(ipLineEdit);
    mainLayout->addWidget(new QLabel("Port :"));
    mainLayout->addWidget(portLineEdit);
    mainLayout->addWidget(connectButton);
    mainLayout->addWidget(disconnectButton);
    mainLayout->addWidget(statusLabel);
    mainLayout->addWidget(new QLabel("Requete :"));
    mainLayout->addWidget(requestComboBox);
    mainLayout->addWidget(sendRequestButton);
    mainLayout->addWidget(responseLabel);

    setLayout(mainLayout);

    connect(connectButton, &QPushButton::clicked, this, &Client::connectToServer);
    connect(disconnectButton, &QPushButton::clicked, this, &Client::disconnectFromServer);
    connect(sendRequestButton, &QPushButton::clicked, this, &Client::sendRequest);
    connect(socket, &QTcpSocket::connected, [this]() {
        statusLabel->setText("Statut : Connecte");
        connectButton->setEnabled(false);
        disconnectButton->setEnabled(true);
        });
    connect(socket, &QTcpSocket::disconnected, [this]() {
        statusLabel->setText("Statut : Non connecte");
        connectButton->setEnabled(true);
        disconnectButton->setEnabled(false);
        });
    connect(socket, &QTcpSocket::readyRead, this, &Client::readServerResponse);
}

Client::~Client() {
    delete socket;
}

void Client::connectToServer() {
    QString ip = ipLineEdit->text();
    quint16 port = portLineEdit->text().toUShort();
    socket->connectToHost(ip, port);
}

void Client::disconnectFromServer() {
    socket->disconnectFromHost();
}

void Client::sendRequest() {
    if (socket->state() == QAbstractSocket::ConnectedState) {
        QString request = requestComboBox->currentText();
        socket->write(request.toUtf8());
    }
}

void Client::readServerResponse() {
    QByteArray response = socket->readAll();
    QString parsedResponse = parseResponse(response);
    responseLabel->setText(parsedResponse);
}

QString Client::parseResponse(const QByteArray& response) {
    QString responseText(response);
    QString result;

    if (responseText.startsWith("Td")) {
        QString sensor = responseText.mid(0, 4);
        QString temperature = responseText.mid(5);
        result = QString("%1 = %2 degre Celsius").arg(sensor).arg(temperature);
    }
    else if (responseText.startsWith("Tf")) {
        QString sensor = responseText.mid(0, 4);
        QString temperature = responseText.mid(5);
        result = QString("%1 = %2 degre Fahrenheit").arg(sensor).arg(temperature);
    }
    else if (responseText.startsWith("Hr")) {
        QString sensor = responseText.mid(0, 4);
        QString humidity = responseText.mid(5);
        result = QString("%1 = %2 %").arg(sensor).arg(humidity);
    }
    else {
        result = "Reponse non valide";
    }

    return result;
}
