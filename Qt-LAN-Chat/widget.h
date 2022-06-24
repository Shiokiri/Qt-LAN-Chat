#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QColorDialog>
#include <QTextCharFormat>

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

    bool saveFile(const QString &fileName);

    void closeEvent(QCloseEvent *);

private:
    Ui::Widget *ui;
    QUdpSocket * udpSocket;
    qint64 port;

    QString fileName;
    TcpServer * server;

    QColor color;


private slots:
    void processPendingDatagrams();

    void on_sendButton_clicked();

    void getFileName(QString);

    void on_sendToolBtn_clicked();
    void on_fontComboBox_currentFontChanged(const QFont &f);
    void on_sizeComboBox_currentIndexChanged(int index);
    void on_sizeComboBox_currentTextChanged(const QString &arg1);
    void on_boldToolBtn_clicked(bool checked);
    void on_italicToolBtn_clicked(bool checked);
    void on_underlineToolBtn_clicked(bool checked);
    void on_colorToolBtn_clicked();

    void currentFormatChanged(const QTextCharFormat &format);

    void on_saveToolBtn_clicked();
    void on_clearToolBtn_clicked();
    void on_exitButton_clicked();
};
#endif // WIDGET_H
