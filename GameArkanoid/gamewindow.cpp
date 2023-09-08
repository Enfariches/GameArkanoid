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
    staredPlatform->setPos(width() / 2, height() - 50);
    scene->addItem(staredPlatform);

    Ball *ball = new Ball();
    ball->setPos((width() / 2), 400);
    scene->addItem(ball);


    ui->graphicsView->setScene(scene);
    ui->graphicsView->horizontalScrollBar()->blockSignals(true);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->verticalScrollBar()->blockSignals(true);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->graphicsView->setFixedSize(800,600);

}

GameWindow::~GameWindow()
{
    delete ui;
}

