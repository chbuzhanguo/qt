#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTcpServer* a=new QTcpServer(this);
    connect(ui->pushButton,&QPushButton::clicked,this,[=]{
        int port=ui->lineEdit->text().toInt();
        if(a->listen(QHostAddress::Any,port))
        {
            ui->label->setText("successs");

        }
        else{ui->label->setText("fail");};
    });

    connect(a,&QTcpServer::newConnection,this,[=]{
        qDebug()<<111;
        QTcpSocket* b=a->nextPendingConnection();
        connect(b,&QTcpSocket::readyRead,this,[=]{
            QString c=b->readAll();
            ui->textEdit->append(c);
            b->write(c.toUtf8());
        });
    });
    qDebug()<<2455556;

}

MainWindow::~MainWindow()
{
    delete ui;
}
