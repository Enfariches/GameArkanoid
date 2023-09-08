#include "gamewindow.h"
#include "ui_gamewindow.h"


GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());

    MoveItem *staredPlatform = new MoveItem();
    staredPlatform->setPos(width() / 2,height() - 50);
    scene->addItem(staredPlatform);
    QPen pen(Qt::black);
    pen.setWidth(10);
    scene->addLine(100,0,100,100,pen);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

GameWindow::~GameWindow()
{
    delete ui;
}

