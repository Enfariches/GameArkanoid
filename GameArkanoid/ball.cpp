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
    return QRectF(0,0,20,20);
}
void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::red);
    painter->drawRect(0,0,20,20);
    painter->drawEllipse(0,0,20,20);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Ball::slotGameTimer()
{
    QList<QGraphicsItem *> foundItems = scene()->items(this->scenePos());
    //qDebug() << foundItems;
    for(auto& item: foundItems)
    {
        if (item == this)
            continue;
        emit signalCheckItem(item);
    }
}

void Ball::timerEvent(QTimerEvent *event)
{
    scene()->advance();
    Q_UNUSED(event);
}

void Ball::advance(int phase)
{
    if(pos().y() > 300)
        this->moveBy(-1,-1);

    else if(pos().y() <= 300)
        this->moveBy(1,-1);

    scene()->update();
    Q_UNUSED(phase);
}

