#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    receiver = new QUdpSocket(this);
    receiver->bind(2048, QUdpSocket::ShareAddress);
    connect(receiver, SIGNAL(readyRead()),
    this, SLOT(processPendingDatagram()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::processPendingDatagram()
{
    while(receiver->hasPendingDatagrams())
    {
       QByteArray datagram;
       datagram.resize(receiver->pendingDatagramSize());
       receiver->readDatagram(datagram.data(),datagram.size());
       ui->label->setText(datagram);
    }
}
