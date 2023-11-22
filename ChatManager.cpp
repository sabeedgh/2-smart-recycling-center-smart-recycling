// chatmanager.cpp
#include "chatmanager.h"

ChatManager::ChatManager(QObject *parent)
    : QObject(parent), socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::readyRead, this, &ChatManager::readyRead);
}

ChatManager::~ChatManager()
{
    delete socket;
}

void ChatManager::connectToServer(const QString &host, int port)
{
    socket->connectToHost(host, port);
}

void ChatManager::sendMessage(const QString &message)
{
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(message.toUtf8());
        socket->flush();
    }
}

void ChatManager::readyRead()
{
    while (socket->canReadLine()) {
        QByteArray data = socket->readLine();
        QString message = QString::fromUtf8(data).trimmed();
        // Extrayez le nom de l'expéditeur du message si nécessaire
        emit messageReceived("Expéditeur", message);
    }
}
