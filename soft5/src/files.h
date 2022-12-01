#ifndef FILES_H
#define FILES_H
#include "input.h"
#include <QWidget>
#include <QPushButton>
#include "output.h"
namespace Ui {
class files;
}

class files : public QWidget
{
    Q_OBJECT

public:
    explicit files(QWidget *parent = nullptr);
    ~files();
    MyOu *m_out;
private slots:
    void on_pushButton_clicked();
    void Recvinput(MyIn* m);
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::files *ui;
    MyIn *f;

};

#endif // FILES_H
