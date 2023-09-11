#include "gamewindow.h"
#include "ui_gamewindow.h"


GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0,0,782,582,this);
    QPen *pen = new QPen();
    pen->setWidth(5);
    scene->addRect(0,0,782,582,*pen);

    MoveItem *staredPlatform = new MoveItem(); // Платформа
    staredPlatform->setPos(width() / 2, height() - 50);
    scene->addItem(staredPlatform);

    Ball *ball = new Ball(); // Мячик
    ball->setPos(782/2,400);
    scene->addItem(ball);
    ball->startTimer(1000/60);

    Blocks *blocks = new Blocks(0,0);
    blocks->startTimer(1000);

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

