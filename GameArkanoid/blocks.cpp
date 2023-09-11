#include "blocks.h"

Blocks::Blocks(QObject *parent, int xspread) :
    QObject(parent), QGraphicsItem()
{
    setPos(xspread,300);
}

QRectF Blocks::boundingRect() const
{
    return QRectF (-75,0,80,20);
}

void Blocks::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(color);
    painter->setPen(Qt::black);
    painter->drawRect(-75,0,80,30);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Blocks::timerEvent(QTimerEvent *event)
{
    qDebug() << this->pos();
    this->scene()->addItem(new Blocks(0,100));
    Q_UNUSED(event);
}
