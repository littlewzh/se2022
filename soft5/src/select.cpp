#include "select.h"
#include "ui_select.h"

Select::Select(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Select)
{
    ui->setupUi(this);
    Init();
}

Select::~Select()
{
    delete ui;
}

void Select::on_pushButton_clicked()
{
    QString strfile = ui->lineEdit->text().trimmed();
    QString typefile = ui->lineEdit_2->text().trimmed();
    qint32 type = typefile.toInt();
    emit SendFile(strfile,type);
}
void Select::Init()
{
    setWindowTitle(tr("select file"));

}
