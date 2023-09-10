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
    return QRectF(-75,70,20,20);
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
    this->scene()->advance();
    Q_UNUSED(event);
}

void Ball::advance(int phase)
{
    if(phase)
    {
        if(pos().y() > 300)
        {
            this->moveBy(-1,-1);
            this->scene()->update();
        }


        else if(pos().y() <= 300)
        {
            this->moveBy(1,-1);
            this->scene()->update();
        }
    }
}

