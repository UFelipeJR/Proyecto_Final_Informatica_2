#ifndef RICK_H
#define RICK_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <resources.h>
#include <QPainter>
#include <mezeek.h>
#include <QRectF>
#include <QSoundEffect>


class mezeek;
class weapon;
class rick: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    QPixmap* torso;
    QPixmap* legs;
    QPixmap* dead;
    QPixmap* weaponTorso;
    QTimer* timer;
    QTimer* punchTimer;
    QTimer* prueba;

    bool alive;
    bool movementActive;
    bool activeWeapon;

    float torsoWidth, torsoLength, legsWidth, legsLength, weaponWidth, weaponLength;
    float rowsTorso, columnsTorso, rowsLegs, columnsLegs, rowsWeapon, columnsWeapon;

    float mass;

    QSoundEffect* punch;
    QList <QGraphicsItem*> CollidingItems;

public:
    rick();
    ~rick();
    void updateSprite();
    void splitSprite();
    void mergeSprites();
    bool getMovementActive() const;
    void setMovementActive(bool newMovementActive);
    bool getActiveWeapon() const;
    void setActiveWeapon(bool newActiveWeapon);
    bool detectCollision();
    bool detectCollision(mezeek* specificMezeek);
    float getkineticEnergy(float vel);
    bool getAlive() const;
    void setAlive(bool newAlive);
    void emitSound(int typeSound);

private slots:
    void animation();
    void punchRick();
    void stopPunch();


};

#endif // RICK_H


