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

    MoveItem *staredPlatform = new MoveItem(); // Платформа
    staredPlatform->setPos(390, myHeight - 50);
    scene->addItem(staredPlatform);

    Ball *ball = new Ball(); // Мячик
    ball->setPos(390, myHeight - 70);
    scene->addItem(ball);
    ball->startTimer(1000/60);

    GenerateTimer = new QTimer(); // Создание блоков
    connect(GenerateTimer, &QTimer::timeout, this, &GameWindow::slotGenerate);
    GenerateTimer->start(50);

    GameTimer = new QTimer(); //Чек на попадаение
    connect(GameTimer, &QTimer::timeout, ball, &Ball::slotGameTimer);
    GameTimer->start(1000/240);

    connect(ball, &Ball::signalCheckItem, this, &GameWindow::slotDelete); //Закрытие окна если мяч падает ниже платформы
    connect(ball, &Ball::signalCloseGame, this, &GameWindow::slotCloseApp);// Связка если шар попал в блок

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
    static int yspread = 5;
    Blocks *block = new Blocks();
    scene->addItem(block);
    block->setPos(xspread, yspread); //10 - 780

    listBlocks.push_back(block);
    xspread += 77;
    qDebug() << yspread;
    if(xspread >= 780)
    {
        xspread = 10;
        yspread += 30;
    }

    if(yspread == 65)
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

void GameWindow::slotCloseApp()
{
    QMessageBox::about(this,"Конец","Мяч вышел за линию платформы");
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

