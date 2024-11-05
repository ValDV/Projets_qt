#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>

class Client : public QWidget {
    Q_OBJECT

public:
    explicit Client(QWidget* parent = nullptr);
    ~Client();

private slots:
    void connectToServer();
    void disconnectFromServer();
    void sendRequest();
    void readServerResponse();

private:
    QLineEdit* ipLineEdit;
    QLineEdit* portLineEdit;
    QComboBox* requestComboBox;
    QPushButton* connectButton;
    QPushButton* disconnectButton;
    QLabel* statusLabel;
    QLabel* responseLabel;

    QTcpSocket* socket;

    QString parseResponse(const QByteArray& response);
};

#endif
