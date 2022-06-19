#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    sender = new QUdpSocket(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QByteArray datagram = "hello world!";
    sender->writeDatagram(datagram.data(),datagram.size(), QHostAddress::Broadcast, 2048);
}

