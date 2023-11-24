#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <QMainWindow>
#include <resources.h>
#include <QCursor>
#include <QScreen>
#include <rick.h>
#include <mezeek.h>
#include <QGraphicsView>
#include <QScreen>
#include <QCursor>
#include <entities.h>
#include <QTimer>
#include <QPainter>
#include <QRandomGenerator>
#include <scenery.h>
#include <conevision.h>
#include <QSurfaceFormat>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class videogame; }
QT_END_NAMESPACE

class videogame : public QMainWindow
{
    Q_OBJECT

private:
    Ui::videogame *ui;

    rick* Rick;
    mezeek* Mezeek;
    QTimer* timerControllers;
    QTimer* timerRotation;
    QGraphicsView *view;
    QGraphicsScene *scene;
    entities* Entities;
    coneVision* circleVision;
    QPropertyAnimation *animation;

    scenery* map1;
    int xCamera;
    int yCamera;

    std::map<char, bool> keyStates;

public:
    videogame(QWidget *parent = nullptr);
    ~videogame();
    void setCustomBackgroundColor(QString color);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void straighten();
    void repairCollision();
    void updateCircleVision();
    void updateMove();
    void rotateRick();
    void moveMezeeks(rick* Rick, mezeek* Mezeek);
    void rotateMezeeks();
    void checkPoint();

public slots:
    void game();
    void killrick();
    void shake();

signals:
    void punch();
    void emitShake();

};
#endif // VIDEOGAME_H
