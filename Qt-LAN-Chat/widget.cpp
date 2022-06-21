#include "widget.h"
#include "ui_widget.h"

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
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);
    port = 45454;
    udpSocket -> bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
    sendMessage(NewParticipant);
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

    qDebug() << localHostName;
    qDebug() << address;
    qDebug() << "sendMessage1";

    switch(type)
    {
        case Message:
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
        break;

        case NewParticipant:
            out << address;
        break;

        case ParticipantLeft:
        break;

        case FileName:
        break;

        case Refuse:
        break;
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
                in >> userName >> localHostName >> ipAddress >> message;
                ui -> messageBrowser -> setTextColor(Qt::blue);
                ui -> messageBrowser -> setCurrentFont(QFont("Times New Roman", 12));
                ui -> messageBrowser -> append("[ " + userName + " ] " + time);
                ui -> messageBrowser -> append(message);
            break;

            case NewParticipant:
                in >> userName >> localHostName >> ipAddress;
                newParticipant(userName, localHostName, ipAddress);
            break;

            case ParticipantLeft:
                in >> userName >> localHostName;
                participantLeft(userName, localHostName, time);
            break;

            case FileName:
            break;

            case Refuse:
            break;

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
    /*
    QStringList envVariables;
    envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
                 << "HOSTNAME.*" << "DOMAINNAME.*";
    */
    QStringList environment = QProcess::systemEnvironment();
    QStringList userNameList = environment.filter("USERNAME");
    foreach(QString string, userNameList)
    {
       QStringList stringList = string.split('=');
       if(stringList.size() == 2 && stringList.at(0) == "USERNAME")
       {
            //qDebug() << stringList.at(1);
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

