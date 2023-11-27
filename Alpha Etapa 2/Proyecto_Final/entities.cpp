#include "entities.h"

entities::entities()
{
    Rick = new rick;
    view = new QGraphicsView;
    scene = new QGraphicsScene;
    screen = QGuiApplication::primaryScreen();
    cameraX = 683;
    cameraY = 384;
    randomFloat = static_cast<float>(std::rand()) / RAND_MAX;

}

entities::entities(rick *Rick, QGraphicsView *view, QGraphicsScene* scene)
{
    this->Rick = Rick;
    this->view  = view;
    this->scene = scene;
    screen = QGuiApplication::primaryScreen();
    cameraX = 683;
    cameraY = 384;
    randomFloat = static_cast<float>(std::rand()) / RAND_MAX;

}

entities::~entities()
{
    delete Rick;
    delete view;
    delete scene;
}

qreal entities::getAngleCursor()
{
    QPoint cursorPosInView = view->mapFromGlobal(QCursor::pos());
    QPointF cursorPosInScene = view->mapToScene(cursorPosInView);

    qreal cursorX = cursorPosInScene.x();
    qreal cursorY = cursorPosInScene.y();

    qreal rectX = Rick->x();
    qreal rectY = Rick->y();

    qreal deltaX = cursorX - rectX;
    qreal deltaY = cursorY - rectY;

    qreal angle = qAtan2(deltaY, deltaX);
    qreal angleG = qRadiansToDegrees(angle);

    return angleG;
}

qreal entities::getAngleEnemy(rick* Rick, mezeek* Mezeek)
{
    qreal RickX = Rick->x();
    qreal RickY = Rick->y();
    qreal MezeekX = Mezeek->x();
    qreal MeezekY = Mezeek->y();

    qreal deltaX = RickX- MezeekX;
    qreal deltaY = RickY - MeezekY;

    qreal angle = qAtan2(deltaY, deltaX);
    qreal angleG = qRadiansToDegrees(angle);

    return angleG;
}

QSize entities::getDimScreen()
{
    QSize screenSize = screen->size();
    return screenSize;
}

float entities::distancetoEnemy(mezeek *Mezeek)
{
    QPointF deltaCoor = Rick->pos()-Mezeek->pos();
    float distance = sqrt(pow(deltaCoor.x(),2)+pow(deltaCoor.y(),2));
    return distance;
}


bool entities::possibilityPunch()
{

    float number = static_cast<float>(std::rand()) / RAND_MAX;

    if (number > randomFloat){
        return false;
    } else {
        return true;
    }



}












