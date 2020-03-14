#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void slotAlarmTimer();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    QTimer *timer;
};

#endif // DIALOG_H
