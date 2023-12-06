#include "scenery.h"

scenery::scenery()
{
    Scene = new QPixmap();
    maskScene = new QPixmap();
}

scenery::scenery(QString pathScenery, QString maskScenery, float scale)
{
    Scene = new QPixmap();
    maskScene = new QPixmap();
    collisions = new QGraphicsPixmapItem;

    try {
        Scene->load(pathScenery);
        maskScene->load(maskScenery);

        if (Scene->isNull() || maskScene->isNull()) {
            throw std::runtime_error("Error al cargar la imagen o la máscara");
        }

        *Scene = Scene->scaled(Scene->width()*scale, Scene->height()*scale);
        *maskScene = maskScene->scaled(maskScene->width()*scale, maskScene->height()*scale);
        setPixmap(*Scene);
        collisions->setPixmap(*maskScene);
        qDebug() << "¡Carga exitosa de escenario y máscara!";

    } catch (const std::exception &e) {

        qDebug() << "Excepción en el constructor: " << e.what();
    }
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




