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
    return QRectF (0,0,150,20);
}

void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawRect(0,0,150,20);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF newPos = event->pos();
    QPointF delta = newPos - offset;

    setX(pos().x() + delta.x());

    if(this->pos().x() < -75)
        setPos(0,pos().y());

    else if(pos().x() > 715)
        setPos(640,pos().y());


}

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    offset = event->pos();
    this->setCursor(QCursor(Qt::ClosedHandCursor));
}

