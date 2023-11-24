#ifndef CONEVISION_H
#define CONEVISION_H

#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>
#include <rick.h>
class coneVision: public QGraphicsRectItem
{

private:
    QRectF boundingRect;

public:
    coneVision();
    coneVision(qreal x, qreal y, qreal width, qreal height);
    QRectF getBoundingRect() const;
    void setBoundingRect(const QRectF &newBoundingRect);
    bool checkIntersection(rick* Rick);
};

#endif // CONEVISION_H
