#ifndef CONEVISION_H
#define CONEVISION_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <rick.h>

class coneVision: public QGraphicsRectItem
{

private:
    QRectF boundingRect;

public:
    coneVision();
    coneVision(qreal x, qreal y, qreal width, qreal height, int opacity);
    QRectF getBoundingRect() const;
    void setBoundingRect(const QRectF &newBoundingRect);
    bool checkIntersection(rick* Rick);
};

#endif // CONEVISION_H
