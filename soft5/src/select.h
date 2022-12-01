#ifndef SELECT_H
#define SELECT_H

#include <QWidget>

namespace Ui {
class Select;
}

class Select : public QWidget
{
    Q_OBJECT

public:
    explicit Select(QWidget *parent = nullptr);
    ~Select();
signals:
    void SendFile(QString,qint32);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Select *ui;
    QString c_file;
    qint32 c_type;
    void Init();
};

#endif // SELECT_H
