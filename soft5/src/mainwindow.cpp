#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();
}

MainWindow::~MainWindow()
{
    //delete m_selectfile; m_selectfile = NULL;
    delete m_pro;m_pro = NULL;
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    m_selectfile = new Select(NULL);
     connect(m_selectfile, SIGNAL(SendFile(QString,qint32)),
            this, SLOT(RecvFile(QString,qint32)) );
    m_selectfile->show();
    m_selectfile->raise();
}
void MainWindow::RecvFile(QString str,qint32 type)
{
    m_filetype.file=str;
    m_filetype.type=type;
    int n1 = m_in->Size();
    m_in->Add(m_filetype.file.toStdString(),m_filetype.type);
    for(;n1<m_in->Size();n1++){
        struct comresult c=m_in->getone(n1);
        QString t = QString::fromStdString(c.file1+"      "+c.file2+"    ")+QString::number(type);
        ui->listWidget->addItem(t);
    }
    delete m_selectfile; m_selectfile = NULL;
    //m_selectfile->hide();
    QMessageBox::information(this, tr("selectfile"), tr("successful"));
}
void MainWindow::Init()
{
    setWindowTitle( tr("PEV Tool") );

    m_selectfile = NULL;
   // m_selectfile = new Select(NULL);
    m_pro = new files(NULL);
     m_in = new MyIn();
    connect(this, SIGNAL(Sendinput(MyIn*)),
            m_pro, SLOT(Recvinput(MyIn*)) );

    //connect(m_selectfile, SIGNAL(SendFile(QString,qint32)),
    //        this, SLOT(RecvFile(QString,qint32)) );
    

}

void MainWindow::on_pushButton_3_clicked()
{
    m_pro->m_out->Print();
    QMessageBox::information(this, tr("print"), tr("successful"));
}

void MainWindow::on_pushButton_clicked()
{
   
    m_pro->show();
    m_pro->raise();
    emit Sendinput(m_in);
}
