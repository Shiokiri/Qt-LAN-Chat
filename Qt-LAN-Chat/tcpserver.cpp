#include "tcpserver.h"
#include "ui_tcpserver.h"

TcpServer::TcpServer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TcpServer)
{
    setFixedSize(350,180) ;
    tcpPort = 6666 ;
    tcpServer = new QTcpServer(this) ;
    connect(tcpServer, SIGNAL(newconnection()),this,SLOT(sendMessage()())) ;

    initServer() ;

    ui->setupUi(this);
}

void TcpServer::initServer()
{
    payloadSize = 64*1024 ;
    TotalBytes = 0 ;
    bytesWritten = 0 ;
    ui - >serverStatusLabel ->setText(tr("请选择要传送的文件")) ;
    ui -> progressBar ->reset();
    ui -> serverOpenBtn -> setEnabled(true);
    ui -> serverSendBtn -> setEnabled(false);
    tcpServer -> close();
}

void TcpServer :: sendMessage()
{
    ui -> serverSendBtn ->setEnabled(false);
    clientConnection = tcpServer -> nextPendingConnection();
    connect(clientConnection, SIGNAL(bytesWritten(qint64)),this,SLOT(updateClientProgress(qint64))) ;
    ui ->serverStatusLabel -> setText(tr("开始传送文件%1!")).arg(theFileName);
    localFile = new(fileName);
    if(!localFile ->open((QFile::ReadOnly))){
        QMessageBox::warning(this,tr("应用程序"),tr("无法读取文件 %1 :\n%2").arg""(theFileName).arg(localFile->errorString()));
        return ;
    }
    TotalBytes = localFile ->size();
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::QT_4_7);
    time.start();
    Qstring currentFile = fileName.right(fileName.size()-fileName.lastIndex('/')-1);
    sendOut<< qint64(0)<<qint64(0)<<currentFile;
    TotalBytes+=outBlock.size();
    sendOut.device()->seek(0);
    sendOut<<TotalBytes <<qint64((outBlock.size()-sizeof (qint64)*2));
    bytestoWrite = TotalBytes - clientConnection ->write(outBlock);
    outBlock.resize(0);
}



TcpServer::~TcpServer()
{
    delete ui;
}
