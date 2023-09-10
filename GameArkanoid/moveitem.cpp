#include "moveitem.h"

MoveItem::MoveItem(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

MoveItem::~MoveItem()
{

}

QRectF MoveItem::boundingRect() const
{
    return QRectF (-75,0,150,20);
}

void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawRect(-75,0,150,20);
}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF newPos = event->scenePos();
    newPos.setY(pos().y());
    setPos(newPos);

    if(pos().x() < 0)
        setPos(100,pos().y());
    else if(pos().x() > 782)
        setPos(700,pos().y());


}

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
}
