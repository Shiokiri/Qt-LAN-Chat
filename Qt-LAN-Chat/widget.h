#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QUdpSocket;

class TcpServer;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

enum MessageType {
    Message, // 消息
    NewParticipant, // 新用户加入
    ParticipantLeft, // 用户退出
    FileName, // 文件名
    Refuse, // 拒绝接收文件
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget * parent = nullptr);
    ~Widget();

protected:
    void newParticipant(QString username,
                        QString localHostName,
                        QString ipAddress);
    void participantLeft(QString userName,
                         QString localHostName,
                         QString time);
    void sendMessage(MessageType type,
                     QString serverAddress = "");

    QString getIP();
    QString getUserName();
    QString getMessage();

    void hasPendingFile(QString userName, QString serverAddress,
                        QString clientAddress, QString fileName);

private:
    Ui::Widget *ui;
    QUdpSocket * udpSocket;
    qint64 port;

    QString fileName;
    TcpServer * server;


private slots:
    void processPendingDatagrams();

    void on_sendButton_clicked();

    void getFileName(QString);

    void on_sendToolBtn_clicked();
};
#endif // WIDGET_H
