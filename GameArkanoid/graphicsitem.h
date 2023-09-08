#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>


class GraphicsItem : public QObject, public QGraphicsItem
{
    Q_OBJECT;
public:
    explicit GraphicsItem(QObject *parent = 0);
    ~GraphicsItem();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = nullptr, QWidget *widget = nullptr);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // GRAPHICSITEM_H
