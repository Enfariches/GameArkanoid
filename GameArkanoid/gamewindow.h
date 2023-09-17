#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QScrollBar>
#include <QTimer>
#include <QList>
#include <QMessageBox>
#include <QApplication>
#include <QProcess>
#include "moveitem.h"
#include "ball.h"
#include "blocks.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private slots:
    void slotGenerate();
    void slotDelete(QGraphicsItem *item);
    void slotCloseApp();

private:
    Ui::GameWindow *ui;
    QGraphicsScene *scene;
    QTimer *GenerateTimer;
    QTimer *GameTimer;
    QList<QGraphicsItem*> listBlocks;
};
#endif // GAMEWINDOW_H
