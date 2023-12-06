#ifndef WEAPON_H
#define WEAPON_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <mezeek.h>
#include <resources.h>
#include <QSoundEffect>

class mezeek;
class weapon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QPixmap* weaponS;
    QTimer* time;
    bool launchActive;
    float friction, mass, normalForce, deltaTime;
    float forceFriction, velIni,vel, aFriction, lossSpeed;
    QList <QGraphicsItem*> CollidingItems;
    QSoundEffect* throwW;

public:
    weapon();
    ~weapon();
    bool getLaunchActive() const;
    void setLaunchActive(bool newLaunchActive);
    float getVel() const;
    void setVel(float newVel);
    bool detectCollision(mezeek* specificMezeek);
    void emitSound();





public slots:
    void movement();    
};

#endif // WEAPON_H

