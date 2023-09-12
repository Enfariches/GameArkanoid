#include "gamewindow.h"
#include "ui_gamewindow.h"


GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0,0,790,590,this);
    int myWidth = 790;
    int myHeight = 590;

    QPen *pen = new QPen(); //Рамка
    pen->setWidth(5);
    scene->addRect(0,0,myWidth,myHeight,*pen);

    MoveItem *staredPlatform = new MoveItem(); // Платформа
    staredPlatform->setPos(390, myHeight - 50);
    scene->addItem(staredPlatform);

    Ball *ball = new Ball(); // Мячик
    ball->setPos(380, myHeight - 70);
    scene->addItem(ball);
    ball->startTimer(1000/60);

    GenerateTimer = new QTimer(); // Создание блоков
    connect(GenerateTimer, &QTimer::timeout, this, &GameWindow::slotGenerate);
    GenerateTimer->start(100);

    GameTimer = new QTimer(); //Чек на попадаение
    connect(GameTimer, &QTimer::timeout, ball, &Ball::slotGameTimer);
    GameTimer->start(1000/60);

    connect(ball, &Ball::signalCheckItem, this, &GameWindow::slotDelete); // Связка если шар попал в блок

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

void GameWindow::slotGenerate()
{

    static int xspread = 10;
    Blocks *block = new Blocks();
    scene->addItem(block);
    block->setPos(xspread,5); //10 - 780

    listBlocks.push_back(block);
    xspread += 77;
    if(xspread >= 780)
        GenerateTimer->stop();
}

void GameWindow::slotDelete(QGraphicsItem *item)
{
    for (auto& block : listBlocks)
    {
        if(item == block)
        {
            scene->removeItem(block);
            listBlocks.removeOne(block);
            delete item;
        }
    }
}

