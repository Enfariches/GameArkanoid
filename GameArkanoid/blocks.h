#ifndef BLOCKS_H
#define BLOCKS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QColor>

class Blocks : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
     Blocks(QObject *parent = 0);
    ~Blocks(){};

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    const QColor color = QColor(rand() % 255, rand() % 255, rand() % 255);
};

#endif // BLOCKS_H
