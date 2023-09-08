#include "scenegraphics.h"



void SceneGraphics::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (rectItem.flags() & QGraphicsItem::ItemIsMovable) {
            // Получить предполагаемую позицию элемента
            QPointF newPos = event->scenePos() - offset;

            // Ограничение позиции элемента в пределах игрового поля
            qreal x = qMin(qMax(newPos.x(), 0.0), 800.0 - rectItem.rect().width());
            qreal y = qMin(qMax(newPos.y(), 0.0), 600.0 - rectItem.rect().height());

            // Установить позицию элемента
            rectItem.setPos(x, y);
        }

        QGraphicsScene::mouseMoveEvent(event);
}
