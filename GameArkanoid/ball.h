#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QTimerEvent>
#include <QPainter>
#include <QObject>


class Ball : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Ball(QObject *event = 0);
    ~Ball();

private:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void timerEvent(QTimerEvent *event) override;
};

#endif // BALL_H
