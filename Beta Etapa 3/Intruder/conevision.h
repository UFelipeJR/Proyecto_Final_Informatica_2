#ifndef CONEVISION_H
#define CONEVISION_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include <rick.h>

class coneVision: public QGraphicsRectItem
{


public:
    coneVision();
    coneVision(qreal x, qreal y, qreal width, qreal height, int opacity);
    bool checkIntersection(rick* Rick);
};

#endif // CONEVISION_H
