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


bool scenery::detectCollision(rick *Rick)
{
    QRectF rect = Rick->boundingRect();
    QPointF pos = Rick->pos();
    QGraphicsRectItem rectItem(rect);
    rect.translate(pos);
    rectItem.setPos(pos);

    if(rectItem.collidesWithItem(collisions)){
        return true;
    }
    else{
        return false;
    }
}


int scenery::direction(rick *Rick)
{
    QRectF rectRick = Rick->boundingRect();
    QPointF posRick = Rick->pos();
    QGraphicsRectItem rectItemRick(rectRick);

    QPointF centerRick;
    QPointF centerCollisions;

    qreal dx;
    qreal dy;
    rectItemRick.setPos(posRick);

    if (rectItemRick.collidesWithItem(collisions)) {
        centerRick = posRick + QPointF(rectRick.width() / 2, rectRick.height() / 2);
        centerCollisions = collisions->pos() + QPointF(collisions->boundingRect().width() / 2, collisions->boundingRect().height() / 2);

        dx = centerCollisions.x() - centerRick.x();
        dy = centerCollisions.y() - centerRick.y();

        if (qAbs(dx) > qAbs(dy)) {
            if (dx > 0) {
                qDebug() << "Colisión detectada a la izquierda de Rick.";
                    return 1;
            } else {
                qDebug() << "Colisión detectada a la derecha de Rick.";
                    return 2;
            }
        } else {
            if (dy > 0) {
                qDebug() << "Colisión detectada arriba de Rick.";
                    return 3;
            } else {
                qDebug() << "Colisión detectada abajo de Rick.";
                    return 4;
            }
        }

        return -1;
    }
}










