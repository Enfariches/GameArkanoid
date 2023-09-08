#include "ball.h"

Ball::Ball(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

Ball::~Ball()
{

}

QRectF Ball::boundingRect() const
{
    return QRectF(-75,0,20,20);
}
void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::red);
    painter->drawEllipse(-75,70,20,20);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Ball::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
}
