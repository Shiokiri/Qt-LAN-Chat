#ifndef TCPSERVER_H
#define TCPSERVER_H

#include<QDialog>
#include<QTcpServer>
#include<QFile>
#include<QTcpSocket>
#include<QTime>
#include<QFileDialog>
#include<QString>
#include<QCloseEvent>
#include<QWidget>
#include<QKeyEvent>
#include<QHostAddress>
#include<QElapsedTimer>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class TcpServer;
}
QT_END_NAMESPACE

class QTcpServer;
class QTcpSocket;

class TcpServer : public QDialog
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = nullptr);
    ~TcpServer();

    void initServer();

    void refused();

protected:
    void closeEvent(QCloseEvent *);

signals:
   void sendFileName(QString );

private slots:
    void on_serverOpenBtn_clicked();
    void on_serverSendBtn_clicked();
    void on_serverCloseBtn_clicked();

    void sendMessage();

    void updateClientProgress(qint64);

private:
    Ui::TcpServer *ui;

    QTcpServer *tcpServer;
    QTcpSocket *clientConnection;
    qint16 tcpPort;
    QFile *localFile ;

    qint64 payloadSize ;
    qint64 TotalBytes ;
    qint64 bytesWritten ;
    qint64 bytestoWrite;

    QString theFileName;
    QString fileName;


    QElapsedTimer elapsedTimer;
    QByteArray outBlock;

};

#endif
