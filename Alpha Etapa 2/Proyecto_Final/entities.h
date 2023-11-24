#ifndef ENTITIES_H
#define ENTITIES_H

#include <QObject>
#include <rick.h>
#include <QGraphicsView>
#include <map>
#include <QKeyEvent>
#include <QGuiApplication>
#include <QScreen>
#include <Qlist>

class entities: public QObject
{
    Q_OBJECT
private:
    rick* Rick;
    QGraphicsView* view;
    QGraphicsScene* scene;
    int cameraX, cameraY;
    QScreen *screen;
    float randomFloat;

public:
    entities();
    entities(rick *Rick, QGraphicsView *view, QGraphicsScene* scene);
    ~entities();
    qreal getAngleCursor();
    qreal getAngleEnemy(rick* Rick, mezeek* Mezeek);
    QSize getDimScreen();
    float distancetoEnemy(mezeek* Mezeek);
    bool possibilityPunch();

    float xMRUA(mezeek* Mezeek);
    int getCameraX() const;
    void setCameraX(int newCameraX);
    int getCameraY() const;
    void setCameraY(int newCameraY);



};

#endif // ENTITIES_H
