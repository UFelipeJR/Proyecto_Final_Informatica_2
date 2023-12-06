#include "particle.h"

particle::particle()
{
    angle = 0.0;
    radius = 300;
    angularSpeed = 0.1;
    centripetalAcceleration = 0.05;
}

particle::particle(qreal radius) : QGraphicsEllipseItem(-radius, -radius, 2 * radius, 2 * radius)
{

    QRadialGradient gradient(0, 0, radius);
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(0.5, QColor(24, 130, 199));
    gradient.setColorAt(1, Qt::transparent);
    setBrush(QBrush(gradient));
    setPen(Qt::NoPen);

    this->radius = 100;
    angle = 0.0;
    angularSpeed = 0.1;
    centripetalAcceleration = 0.05;
}

void particle::updatePosition(qreal xP, qreal yP)
{
    qreal dt = 0.1;
    angularSpeed += centripetalAcceleration * dt;
    angle += angularSpeed * dt;
    qreal x = xP + radius * qCos(angle);
    qreal y = yP + radius * qSin(angle);
    setPos(x, y);
}

bool particle::detectCollision(mezeek *specificMezeek)
{
    CollidingItems = collidingItems();
    for(int i = 0; i < CollidingItems.size(); i++){
        if(typeid(*CollidingItems[i]) == typeid(mezeek)){
            mezeek* mezeekItem = dynamic_cast<mezeek*>(CollidingItems[i]);
            if (mezeekItem && mezeekItem == specificMezeek && mezeekItem->getAlive()) {
                return true;
            }
        }
    }
    return false;
}





