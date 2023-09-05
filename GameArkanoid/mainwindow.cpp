#include "mainwindow.h"
#include "gamewindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setFixedSize(width(),height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitButton_clicked()
{
    MainWindow::close();
}

void MainWindow::on_startButton_clicked()
{
    MainWindow::close();
    GameWindow game(this);
    game.setModal(true);
    game.exec();
}
