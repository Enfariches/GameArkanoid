#include "graphicsitem.h"

GraphicsItem::GraphicsItem(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

GraphicsItem::~GraphicsItem()
{

}

QRectF GraphicsItem::boundingRect() const
{
    return QRectF(-30,-30,60,60);
}

void GraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawRect(-30,-30,60,60);
}

void GraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void GraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
}
