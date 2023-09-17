#include "ball.h"

Ball::Ball(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    path = QPointF(1 , -1);
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
    QList<QGraphicsItem *> foundItems = scene()->items(mapToScene(this->boundingRect()));
    for(auto& item: foundItems)
    {
        if (item == this || item->boundingRect().width() == 150)
            continue;

        QRectF rectItem = item->boundingRect();
        if(pos().x() < rectItem.left() || pos().x() + boundingRect().width() > rectItem.right())
            path.setX(-path.x());

        if(pos().y() < rectItem.top() || pos().y() + boundingRect().height() > rectItem.bottom())
            path.setY(-path.y());

        emit signalCheckItem(item);
    }
}

void Ball::timerEvent(QTimerEvent *event)
{
    scene()->advance();
    if(this->scenePos().y() > 550)
    {
       this->killTimer(event->timerId());
       emit(signalCloseGame());
    }

    Q_UNUSED(event);
}

void Ball::advance(int phase)
{
    QRectF sceneRect = scene()->sceneRect();

    if(pos().x() < sceneRect.left() || pos().x() + boundingRect().width() > sceneRect.right())
        path.setX(-path.x());

    if(pos().y() < sceneRect.top() || pos().y() + boundingRect().height() > sceneRect.bottom())
        path.setY(-path.y());

    QList<QGraphicsItem*> items = this->collidingItems();
    for(auto& item : items)
    {
        if(item->boundingRect().width() == 150)
        {
            QRectF rectItem = item->boundingRect();
            if (pos().y() < rectItem.top() || pos().y() + boundingRect().width() > rectItem.bottom()) {
                path.setY(-path.y());
            }
        }

    }

    moveBy(path.x(), path.y());

    Q_UNUSED(phase);
}





