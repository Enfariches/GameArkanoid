#ifndef ITEMMOVE_H
#define ITEMMOVE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsItem>

class ItemMove : public QGraphicsItem
{
    Q_OBJECT
public:
    ItemMove();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void mouseMoveEvent(QGraphicsSceneMouseEvent*);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*);

};

#endif // ITEMMOVE_H
