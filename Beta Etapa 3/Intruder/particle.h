#ifndef PARTICLE_H
#define PARTICLE_H

#include <QGraphicsEllipseItem>
#include <QRadialGradient>
#include <QBrush>
#include <QPen>
#include <mezeek.h>

class particle: public QGraphicsEllipseItem
{

private:
    qreal angle;
    qreal radius;
    qreal angularSpeed;
    qreal centripetalAcceleration;
    QList <QGraphicsItem*> CollidingItems;

public:
    particle();
    particle(qreal radius);
    void updatePosition(qreal xP, qreal yP);
    bool detectCollision(mezeek* specificMezeek);
};

#endif // PARTICLE_H
