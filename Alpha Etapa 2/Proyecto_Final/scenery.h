#ifndef SCENERY_H
#define SCENERY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <rick.h>

class scenery: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QPixmap* Scene;
    QPixmap* maskScene;
    QGraphicsPixmapItem * collisions;

public:
    scenery();
    scenery(QString pathScenery, QString maskScenery);
    ~scenery();
    //bool detectCollision(rick* Rick);
    bool detectCollision(rick* Rick);
    int direction(rick* Rick);
};

#endif // SCENERY_H
