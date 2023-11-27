#ifndef SCENERY_H
#define SCENERY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <rick.h>
#include <mezeek.h>
#include <weapon.h>

class scenery: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QPixmap* Scene;
    QPixmap* maskScene;
    QGraphicsPixmapItem* collisions;

public:
    scenery();
    scenery(QString pathScenery, QString maskScenery);
    ~scenery();

    bool detectCollision(rick* Rick, int x, int y);
    bool detectCollision(mezeek* Mezeek, int x, int y);
    bool detectCollision(weapon* Weapon, int x, int y);
};

#endif // SCENERY_H
