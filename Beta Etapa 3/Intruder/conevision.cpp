#include "conevision.h"

coneVision::coneVision()
{
    setRect(0, 0, 100, 100);
    QBrush brush(QColor(0, 255, 0, 0));
    setBrush(brush);
}

coneVision::coneVision(qreal x, qreal y, qreal width, qreal height, int opacity) : QGraphicsRectItem(x, y, width, height) {

    QPen pen;
    QBrush brush(QColor(0, 255, 0, opacity));
    setBrush(brush);
    pen.setColor(Qt::transparent);
    pen.setWidth(0);
    setPen(pen);
}

bool coneVision::checkIntersection(rick *Rick)
{

    if(this->collidesWithItem(Rick)){
        return true;
    }
    else{
        return false;
    }


}




