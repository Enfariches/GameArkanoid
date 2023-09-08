#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QScrollBar>
#include "moveitem.h"
#include "ball.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    Ui::GameWindow *ui;
    QGraphicsScene *scene;
};

#endif // GAMEWINDOW_H
