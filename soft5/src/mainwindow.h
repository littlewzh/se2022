#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "select.h"
#include "input.h"
#include "files.h"
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
struct File_type{
    QString file;
    qint32 type;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


signals:
    void Sendinput(MyIn* in);
private slots:
    void on_pushButton_2_clicked();
    void RecvFile(QString str,qint32 type);
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    struct File_type m_filetype;
    //QString m_file;
    Select* m_selectfile;
    files* m_pro;
    MyIn* m_in;
    void Init();
};
#endif // MAINWINDOW_H
