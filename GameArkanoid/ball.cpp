#include "ball.h"

Ball::Ball(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    path = QPointF(1, -1);
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
    painter->drawEllipse(0,0,20,20);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Ball::slotGameTimer()
{
    QList<QGraphicsItem *> foundItems = scene()->items(this->scenePos());
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
    QRectF sceneRect = scene()->sceneRect();

    if(pos().x() < sceneRect.left() || pos().x() + boundingRect().width() > sceneRect.right())
    {
        path.setX(-path.x());
    }

    if(pos().y() < sceneRect.top() || pos().y() + boundingRect().width() > sceneRect.bottom())
    {
        path.setY(-path.y());
    }

    moveBy(path.x(), path.y());
    Q_UNUSED(phase);
}



