#include "blocks.h"

Blocks::Blocks(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

QRectF Blocks::boundingRect() const
{
    return QRectF (0,0,77,30);
}

void Blocks::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(color);
    painter->setPen(Qt::black);
    painter->drawRect(0,0,77,30);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
