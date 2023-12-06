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
#include <QBrush>
#include <QPen>
#include <weapon.h>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <particle.h>
#include <text.h>
#include <QLabel>
#include <QSoundEffect>
#include <headmezeek.h>

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
    QTimer* timerDeath;
    QTimer* timerParticle;
    QTimer* timerFinishPowerUp;
    QTimer* timerMenu;

    QGraphicsView *view;
    QGraphicsScene *scene;
    entities* Entities;
    coneVision* circleVision;
    QSoundEffect* OST;

    QList<scenery*> maps;
    QList<text*> listText;
    QList<mezeek*> listMezeek;
    QList<coneVision*> listConeVision;
    QList<headMezeek*> heads;

    particle* ability;

    QGraphicsRectItem *rectangleScreen;
    QGraphicsOpacityEffect *opacityEffect;
    QPropertyAnimation *animationOF;


    int xCamera;
    int yCamera;
    int level;
    unsigned long long int contEnergy;
    unsigned short int percentage;

    std::map<char, bool> keyStates;
    int n = 0;


public:
    videogame(QWidget *parent = nullptr);
    ~videogame();
    void setCustomBackgroundColor(QString color);
    void setCustomBackgroundColor(QColor startColor, QColor endColor);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void straighten();
    void updateMove(int numMap);
    void rotateRick();
    void moveMezeeks(rick* Rick, mezeek* Mezeek, int numCone, int numMap);
    void rotateMezeeks(int numMezeek);
    void checkPoint();
    void activePowerUp();
    void viewText();
    void level1();
    void loadKineticEnergy(float vel);
    void detectKill(int numMezeek);
    void spawnMezeeks();
    void removeAllMezeeks();
    void removeAllCones();
    void animation();
    bool thereMezeeks();
    void rightButton();
    void leftButton();

private slots:
    void game();
    void throwWeapon();
    void powerUp();
    void initVideoGame();
    void killrick();
    void finish();
    void menuAnimation();
    void level2();

signals:
    void punch();
    void changeLevel();


};
#endif // VIDEOGAME_H
