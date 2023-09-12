#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QScrollBar>
#include <QDebug>
#include <QTimer>
#include <QList>
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

private:
    Ui::GameWindow *ui;
    QGraphicsScene *scene;
    QTimer *GenerateTimer;
    QList<QGraphicsItem*> listBlocks;
};
#endif // GAMEWINDOW_H
