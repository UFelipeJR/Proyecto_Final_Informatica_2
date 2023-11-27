#include "scenery.h"

scenery::scenery()
{
    Scene = new QPixmap();
    maskScene = new QPixmap();
}

scenery::scenery(QString pathScenery, QString maskScenery)
{
    const float scale = 2.5;
    Scene = new QPixmap();
    maskScene = new QPixmap();
    collisions = new QGraphicsPixmapItem;

    Scene->load(pathScenery);
    maskScene->load(maskScenery);
    *Scene = Scene->scaled(Scene->width()*scale,Scene->height()*scale);
    *maskScene = maskScene->scaled(maskScene->width()*scale,maskScene->height()*scale);
    setPixmap(*Scene);
    collisions->setPixmap(*maskScene);
}

scenery::~scenery()
{
    delete Scene;
    delete maskScene;

}

bool scenery::detectCollision(rick *Rick, int x, int y)
{
    QRectF rect = Rick->boundingRect();
    QPointF pos = Rick->pos();
    QGraphicsRectItem rectItem(rect);

    pos.setX(pos.x() + x);
    pos.setY(pos.y() + y);
    rectItem.setPos(pos);

    if (rectItem.collidesWithItem(collisions)) {
        return true;
    } else {
        return false;
    }
}

bool scenery::detectCollision(mezeek *Mezeek, int x, int y)
{
    QRectF rect = Mezeek->boundingRect();
    QPointF pos = Mezeek->pos();
    QGraphicsRectItem rectItem(rect);

    pos.setX(pos.x() + x);
    pos.setY(pos.y() + y);
    rectItem.setPos(pos);

    if (rectItem.collidesWithItem(collisions)) {
        return true;
    } else {
        return false;
    }
}

bool scenery::detectCollision(weapon *Weapon, int x, int y)
{
    QRectF rect = Weapon->boundingRect();
    QPointF pos = Weapon->pos();
    QGraphicsRectItem rectItem(rect);

    pos.setX(pos.x() + x);
    pos.setY(pos.y() + y);
    rectItem.setPos(pos);

    if (rectItem.collidesWithItem(collisions)) {
        return true;
    } else {
        return false;
    }
}



