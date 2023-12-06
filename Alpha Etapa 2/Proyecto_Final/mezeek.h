#ifndef MEZEEK_H
#define MEZEEK_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <resources.h>
#include <QPainter>
#include <cmath>
#include <rick.h>
#include <weapon.h>


class rick;
class weapon;
class mezeek: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QPixmap* torso;
    QPixmap* legs;
    QPixmap* dead;
    QPixmap* lyingSprite;
    QTimer* timer;

    bool movementActive;
    bool acelerationActive;
    bool alive;
    bool confirmation;
    bool activePunch;
    bool lying;

    float torsoWidth, torsoLength, legsWidth, legsLength;
    float rowsTorso, columnsTorso, rowsLegs, columnsLegs;

    QList <QGraphicsItem*> CollidingItems;


    //physicals
    QTimer* physicalTimer;
    float T,velIni,g,t,k;
    float aX;
    unsigned int n;


public:
    mezeek();
    ~mezeek();
    void updateSprite();
    void splitSprite();
    bool getAlive() const;
    void setAlive(bool newAlive);
    void mergeSprites();
    bool detectCollision();
    bool getConfirmation() const;
    void setConfirmation(bool newConfirmation);
    bool getMovementActive() const;
    void setMovementActive(bool newMovementActive);
    float getAX() const;
    float getT() const;
    bool getAcelerationActive() const;
    void setAcelerationActive(bool newAcelerationActive);
    bool getLying() const;
    void setLying(bool newLying);

private slots:
    void animation();
    void calcAcelerationX();
    void attack();

signals:
    void killRick();


};



#endif // MEZEEK_H
