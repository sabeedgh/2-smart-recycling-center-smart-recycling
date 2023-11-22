#ifndef CHATMANAGER_H
#define CHATMANAGER_H
#include <QObject>
#include <QTcpSocket>

class ChatManager : public QObject
{
    Q_OBJECT

public:
    explicit ChatManager(QObject *parent = nullptr);
    ~ChatManager();

    void connectToServer(const QString &host, int port);
    void sendMessage(const QString &message);

signals:
    void messageReceived(const QString &sender, const QString &message);

private slots:
    void readyRead();

private:
    QTcpSocket *socket;
};

#endif // CHATMANAGER_H
