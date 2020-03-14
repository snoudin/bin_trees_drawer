#include "dialog.h"
#include "ui_dialog.h"

#include <queue>

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    timer = new QTimer();
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(50);
}

Dialog::~Dialog()
{
    delete ui;
}

extern std :: queue<QLine> to_draw;

void Dialog::slotAlarmTimer(){
    int width = ui->graphicsView->width();
    int height = ui->graphicsView->height();
    scene->setSceneRect(10, 10, width - 20,height - 20);
    QPen penBlack(Qt::black);
    while (!to_draw.empty()){
        scene->addLine(to_draw.front());
        to_draw.pop();
    }
}

void Dialog::on_pushButton_clicked()
{
    QString filename = "res.jpg";
    QPixmap pixmap = ui->graphicsView->grab(ui->graphicsView->sceneRect().toRect());
    pixmap.save(filename);
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}
