#include "itemmove.h"

ItemMove::ItemMove()
{

}

void ItemMove::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
    if (x() < 0)
            setPos(0, y());
        else if (x() > 800)
            setPos(800, y());

        if (y() < 0)
            setPos(x(), 0);
        else if (y() > 600)
            setPos(x(), 600);
}
