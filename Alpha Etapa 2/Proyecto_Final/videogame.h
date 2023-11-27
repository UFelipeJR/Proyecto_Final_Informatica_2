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
#include <QBrush>
#include <QPen>
#include <weapon.h>

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
    weapon* bat;
    QTimer* timerControllers;
    QTimer* timerRotation;
    QGraphicsView *view;
    QGraphicsScene *scene;
    entities* Entities;
    coneVision* circleVision;
    scenery* map1;
    QGraphicsTextItem* textReset;
    QGraphicsTextItem* points;
    QGraphicsTextItem* combo;

    int xCamera;
    int yCamera;
    int level;

    std::map<char, bool> keyStates;

public:
    videogame(QWidget *parent = nullptr);
    ~videogame();
    void setCustomBackgroundColor(QString color);
    void setCustomBackgroundColor(QColor startColor, QColor endColor);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void straighten();
    void updateCircleVision();
    void updateMove();
    void rotateRick();
    void moveMezeeks(rick* Rick, mezeek* Mezeek);
    void rotateMezeeks();
    void checkPoint();
    void viewText();
    void level1();

private slots:
    void game();
    void killrick();
    void throwWeapon();

signals:
    void punch();


};
#endif // VIDEOGAME_H
