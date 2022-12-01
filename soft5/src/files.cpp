#include "files.h"
#include "ui_files.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include "main.h"
files::files(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::files)
{
    ui->setupUi(this);
    m_out = new MyOu();
}

files::~files()
{
    delete ui;
}
void files::Recvinput(MyIn* m)
{
    f=m;
    if(f->Size()==0){
        QMessageBox::information(this, tr("readfile"), tr("no input"));
        return;
    }
    struct comresult tmp=f->getone(f->Ord());
    //cout<<tmp.file1<<"    "<<tmp.file2<<endl;
    if(tmp.flag==1){
        ui->textBrowser->setPlainText("equal");
    }else{
        ui->textBrowser->setPlainText("inequal");
    }
    //f->Ordadd();
    ui->textBrowser_1->setPlainText(QString::fromStdString(tmp.file1));
    //ui->textBrowser_1->show();
    ui->textBrowser_2->setPlainText(QString::fromStdString(tmp.file2));
    //ui->textBrowser_2->show();
    string path=FILEPATH;
    //QMessageBox::information(this, tr("readfile"), tr("successful"));
    QFile file1(QString::fromStdString(path+tmp.file1+".cpp"));
    if(!file1.open(QFile::ReadOnly))
        qDebug()<<"Can not open";
    QTextStream in1(&file1);
    ui->textBrowser_3->setPlainText(in1.readAll());
    QFile file2(QString::fromStdString(path+tmp.file2+".cpp"));
    if(!file2.open(QFile::ReadOnly))
        qDebug()<<"Can not open";
    QTextStream in2(&file2);
    ui->textBrowser_4->setPlainText(in2.readAll());

}
void files::on_pushButton_clicked()
{
    if(f->Size()==0){
        QMessageBox::information(this, tr("readfile"), tr("no input"));
        return;
    }
    if(f->Ord()==f->Size()-1){
        QMessageBox::information(this, tr("readfile"), tr("this is the end"));
    }
    else{
        f->Ordadd();
        struct comresult tmp=f->getone(f->Ord());
        //cout<<tmp.file1<<"    "<<tmp.file2<<endl;
        //
        if(tmp.flag==1){
        ui->textBrowser->setPlainText("equal");
    }else{
        ui->textBrowser->setPlainText("inequal");
    }
        ui->textBrowser_1->setPlainText(QString::fromStdString(tmp.file1));
        //ui->textBrowser_1->show();
        ui->textBrowser_2->setPlainText(QString::fromStdString(tmp.file2));
        //ui->textBrowser_2->show();
        string path="/home/wzh/soft/";
        //
        QFile file1(QString::fromStdString(path+tmp.file1+".cpp"));
        if(!file1.open(QFile::ReadOnly))
            qDebug()<<"Can not open";
        QTextStream in1(&file1);
        ui->textBrowser_3->setPlainText(in1.readAll());
        QFile file2(QString::fromStdString(path+tmp.file2+".cpp"));
        if(!file2.open(QFile::ReadOnly))
            qDebug()<<"Can not open";
        QTextStream in2(&file2);
        ui->textBrowser_4->setPlainText(in2.readAll());
    }

}

void files::on_pushButton_3_clicked()
{
    if(f->Size()==0){
        QMessageBox::information(this, tr("readfile"), tr("no input"));
        return;
    }
    if(f->Ord()==0){
        QMessageBox::information(this, tr("readfile"), tr("this is the start"));
    }
    else{
        f->Orddown();
        struct comresult tmp=f->getone(f->Ord());
        //cout<<tmp.file1<<"    "<<tmp.file2<<endl;
        //
        if(tmp.flag==1){
        ui->textBrowser->setPlainText("equal");
    }else{
        ui->textBrowser->setPlainText("inequal");
    }
        ui->textBrowser_1->setPlainText(QString::fromStdString(tmp.file1));
        //ui->textBrowser_1->show();
        ui->textBrowser_2->setPlainText(QString::fromStdString(tmp.file2));
        //ui->textBrowser_2->show();
        string path="/home/wzh/soft/";
        //
        QFile file1(QString::fromStdString(path+tmp.file1+".cpp"));
        if(!file1.open(QFile::ReadOnly))
            qDebug()<<"Can not open";
        QTextStream in1(&file1);
        ui->textBrowser_3->setPlainText(in1.readAll());
        QFile file2(QString::fromStdString(path+tmp.file2+".cpp"));
        if(!file2.open(QFile::ReadOnly))
            qDebug()<<"Can not open";
        QTextStream in2(&file2);
        ui->textBrowser_4->setPlainText(in2.readAll());
    }

}

void files::on_pushButton_2_clicked()
{
    this->hide();
}

void files::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button == static_cast<QAbstractButton *>(ui->buttonBox->button(QDialogButtonBox::Yes))){
        m_out->Add(f->getone(f->Ord()).file1,f->getone(f->Ord()).file2,1);
        QMessageBox::information(this, tr("result"), tr("equal"));
    }
    else if(button == static_cast<QAbstractButton *>(ui->buttonBox->button(QDialogButtonBox::No))){
        m_out->Add(f->getone(f->Ord()).file1,f->getone(f->Ord()).file2,0);
        QMessageBox::information(this, tr("result"), tr("inequal"));
    }
}
