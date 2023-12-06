#include "conevision.h"

coneVision::coneVision()
{
    setRect(0, 0, 100, 100);
    boundingRect = QRectF(0, 0, 100, 100);
    QBrush brush(QColor(0, 255, 0, 0));
    setBrush(brush);
}

coneVision::coneVision(qreal x, qreal y, qreal width, qreal height, int opacity) : QGraphicsRectItem(x, y, width, height) {

    boundingRect.setRect(x, y, width, height);
    QPen pen;
    QBrush brush(QColor(0, 255, 0, opacity));
    setBrush(brush);
    pen.setColor(Qt::transparent);
    pen.setWidth(0);
    setPen(pen);
}

bool coneVision::checkIntersection(rick *Rick)
{
    QRectF rect = Rick->boundingRect();
    QPointF pos = Rick->pos();
    rect.translate(pos);

    if (rect.intersects(boundingRect)) {
        return true;
    } else {
        return false;
    }

}

QRectF coneVision::getBoundingRect() const
{
    return boundingRect;
}


void coneVision::setBoundingRect(const QRectF &newBoundingRect)
{
    boundingRect = newBoundingRect;
}



