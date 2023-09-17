#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QTimerEvent>
#include <QPainter>
#include <QObject>
#include <QGraphicsScene>
#include <gamewindow.h>


class Ball : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Ball(QObject *event = 0);
    ~Ball();

private:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QPointF path;

signals:
    void signalCheckItem(QGraphicsItem *item);
    void signalCloseGame();

public slots:
    void slotGameTimer();

protected:
    void timerEvent(QTimerEvent *event) override;
    virtual void advance(int phase) override;
};

#endif // BALL_H
