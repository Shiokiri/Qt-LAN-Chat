#include "widget.h"
#include "ui_widget.h"

#include "tcpserver.h"
#include "tcpclient.h"
#include <QFileDialog>

#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QscrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui -> setupUi(this);

    udpSocket = new QUdpSocket(this);
    port = 45454;

    udpSocket -> bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);

    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
    sendMessage(NewParticipant);

    server = new TcpServer(this);
    connect(server, SIGNAL(sendFileName(QString)), this, SLOT(getFileName(QString)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::sendMessage(MessageType type, QString serverAddress)
{
    qDebug() << "sendMessage0";

    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);

    QString localHostName = QHostInfo::localHostName();
    QString address = getIP();

    out << type << getUserName() << localHostName;

    //qDebug() << localHostName;
    //qDebug() << address;
    qDebug() << "sendMessage1";

    switch(type)
    {
        case Message:
        {
            qDebug() << "sendMessage Message begin";
            if(ui -> messageTextEdit -> toPlainText() == "")
            {
                QMessageBox::warning(0,
                                     tr("警告"),
                                     tr("发送内容不能为空"),
                                     QMessageBox::Ok);
                return;
            }
            out << address << getMessage();
            ui -> messageBrowser -> verticalScrollBar()
               -> setValue(ui -> messageBrowser -> verticalScrollBar() -> maximum());
            qDebug() << "sendMessage Message end";
            break;
        }

        case NewParticipant:
        {
            out << address;
            break;

        }

        case ParticipantLeft:
        {
            break;
        }

        case FileName:
        {
            qDebug() << "sendMessage FileName begin";
            int row = ui -> userTableWidget -> currentRow();
            QString clientAddress = ui -> userTableWidget -> item(row, 2) -> text();
            out << address << clientAddress << fileName;
            qDebug() << "sendMessage FileName end";
            break;
        }

        case Refuse:
        {
            out << serverAddress;
            break;
        }
    }
    udpSocket -> writeDatagram(data, data.length(),
                               QHostAddress::Broadcast,
                               port);
}

void Widget::processPendingDatagrams()
{
    qDebug() << "processPendingDatagrams";

    while(udpSocket -> hasPendingDatagrams())
    {
        QByteArray datagram;

        datagram.resize(udpSocket -> pendingDatagramSize());
        udpSocket -> readDatagram(datagram.data(), datagram.size());

        QDataStream in(&datagram, QIODevice::ReadOnly);

        int messageType;
        in >> messageType;
        QString userName, localHostName, ipAddress, message;

        QString time = QDateTime::currentDateTime()
                .toString("yyyy-MM-dd hh:mm:ss");

        switch(messageType)
        {
            case Message:
            {
                in >> userName >> localHostName >> ipAddress >> message;

                ui -> messageBrowser -> setTextColor(Qt::blue);
                ui -> messageBrowser -> setCurrentFont(QFont("Times New Roman", 12));
                ui -> messageBrowser -> append("[ " + userName + " ] " + time);
                ui -> messageBrowser -> append(message);

                break;
            }

            case NewParticipant:
            {
                in >> userName >> localHostName >> ipAddress;
                newParticipant(userName, localHostName, ipAddress);
                break;

            }

            case ParticipantLeft:
            {
                in >> userName >> localHostName;
                participantLeft(userName, localHostName, time);
                break;
            }

            case FileName:
            {
                qDebug() << "FileName1";
                in >> userName >> localHostName >> ipAddress;
                QString clientAddress, fileName;
                in >> clientAddress >> fileName;
                qDebug() << "FileName2";
                hasPendingFile(userName, ipAddress, clientAddress, fileName);
                qDebug() << "FileName end";
                break;
            }

            case Refuse:
            {
                in >> userName >> localHostName;
                QString serverAddress;
                in >> serverAddress;
                QString ipAddress = getIP();
                if(ipAddress == serverAddress)
                {
                    server -> refused();
                }
                break;
            }

        }

    }

}

void Widget::newParticipant(QString userName, QString localHostName, QString ipAddress)
{
    qDebug() << "newParticipant";

    bool isEmpty = ui -> userTableWidget
            -> findItems(localHostName, Qt::MatchExactly).isEmpty();

    if(isEmpty)
    {
        QTableWidgetItem * user = new QTableWidgetItem(userName);
        QTableWidgetItem * host = new QTableWidgetItem(localHostName);
        QTableWidgetItem * ip = new QTableWidgetItem(ipAddress);

        ui -> userTableWidget -> insertRow(0);
        ui -> userTableWidget -> setItem(0, 0, user);
        ui -> userTableWidget -> setItem(0, 1, host);
        ui -> userTableWidget -> setItem(0, 2, ip);

        ui -> messageBrowser -> setTextColor(Qt::gray);
        ui -> messageBrowser -> setCurrentFont(QFont("Times New Roman", 10));
        ui -> messageBrowser -> append(tr("%1在线！").arg(userName));

        ui -> userNumLabel -> setText(tr("在线人数：%1")
                                      .arg(ui -> userTableWidget -> rowCount()));

        sendMessage(NewParticipant);
    }
}

void Widget::participantLeft(QString userName, QString localHostName, QString time)
{
    int rowNum = ui -> userTableWidget -> findItems(localHostName,
                                                    Qt::MatchExactly).first() -> row();
    ui -> userTableWidget -> removeRow(rowNum);
    ui -> messageBrowser -> setTextColor(Qt::gray);
    ui -> messageBrowser -> setCurrentFont(QFont("Times New Roman", 10));
    ui -> messageBrowser -> append(tr("%1于%2离开！").arg(userName).arg(time));
    ui -> userNumLabel -> setText(tr("在线人数：%1")
                                  .arg(ui -> userTableWidget -> rowCount()));
}

QString Widget::getIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach(QHostAddress address, list)
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
            return address.toString();
    }
    return 0;
}

QString Widget::getUserName()
{
    QStringList environment = QProcess::systemEnvironment();
    QStringList userNameList = environment.filter("USERNAME");

    foreach(QString string, userNameList)
    {
       QStringList stringList = string.split('=');
       if(stringList.size() == 2 && stringList.at(0) == "USERNAME")
       {
            return stringList.at(1);
            break;
       }
    }
    return "unknown";
}

QString Widget::getMessage()
{
    QString msg = ui -> messageTextEdit -> toHtml();

    ui -> messageTextEdit -> clear();
    ui -> messageTextEdit -> setFocus();

    return msg;
}

void Widget::on_sendButton_clicked()
{
    sendMessage(Message);
}

void Widget::getFileName(QString name)
{
    qDebug() << "getFileName";
    fileName = name;
    sendMessage(FileName);
}

void Widget::on_sendToolBtn_clicked()
{
    if(ui -> userTableWidget -> selectedItems().isEmpty())
    {
        QMessageBox::warning(0, tr("选择用户"),
                             tr("请先从用户列表选择要传送的用户！"), QMessageBox::Ok);
        return;
    }
    server -> show();
    server -> initServer();

}

void Widget::hasPendingFile(QString userName,
                            QString serverAddress,
                            QString clientAddress,
                            QString fileName)
{

    qDebug() << "hasPendingFile";

    QString ipAddress = getIP();

    if(ipAddress == clientAddress)
    {
        int btn = QMessageBox::information(this, tr("接收文件"),
                                           tr("来自%1(%2)的文件：%3，是否接收？")
                                           .arg(userName).arg(serverAddress).arg(fileName),
                                           QMessageBox::Yes, QMessageBox::No);
        if(btn == QMessageBox::Yes)
        {
            qDebug() << "hasPendingFile Yes";
            QString name = QFileDialog::getSaveFileName(0, tr("保存文件"), fileName);
            if(!name.isEmpty())
            {
                TcpClient * client = new TcpClient(this);
                client -> setFileName(name);
                client -> setHostAddress(QHostAddress(serverAddress));
                client -> show();
            }
        }
        else
        {
            sendMessage(Refuse, serverAddress);
        }
    }

    qDebug() << "hasPendingFile end";
}
