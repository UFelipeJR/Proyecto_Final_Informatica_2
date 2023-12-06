#include "mezeek.h"

mezeek::mezeek()
{
    torso = new QPixmap();
    legs = new QPixmap();
    dead = new QPixmap();
    lyingSprite = new QPixmap();

    timer = new QTimer();
    physicalTimer = new QTimer();

    movementActive = false;
    alive = true;
    confirmation = false;
    acelerationActive = false;
    activePunch = false;
    lying = false;

    legsWidth = 33;
    legsLength = 32;

    torsoWidth = 33;
    torsoLength = 32;

    rowsTorso = 0;
    columnsTorso = 0;

    rowsLegs = 0;
    columnsLegs = 0;
    velIni = 0.00001;
    g = 9.81;

    T = 0.01;
    n = 0;
    k = 1;

    timer->start(60);
    physicalTimer->start(100*T);
    dead->load(resources::deadMezeek);
    lyingSprite->load(resources::lyingMezeek);
    connect(timer, SIGNAL(timeout()), this, SLOT(animation()));
    connect(timer, SIGNAL(timeout()), this, SLOT(attack()));
    connect(physicalTimer, SIGNAL(timeout()), this, SLOT(calcAcelerationX()));
}

mezeek::~mezeek()
{
    delete torso;
    delete legs;
    delete timer;
    delete dead;
    delete physicalTimer;
}

void mezeek::updateSprite()
{

    if(movementActive){
        rowsTorso += torsoLength;
        rowsLegs += legsLength;
    }
    if(rowsTorso >= SpriteTorsoLengthMezeek || !movementActive){
        rowsTorso = 0;
    }
    if(rowsLegs >= SpriteLegsLengthMezeek){
        rowsLegs = 0;
    }
}

void mezeek::splitSprite()
{
    QPixmap torsoAux(resources::torsoMezeek);
    QPixmap legsAux(resources::legsMezeek);
    *torso = torsoAux.copy(columnsTorso,rowsTorso,torsoWidth,torsoLength);
    *legs = legsAux.copy(columnsLegs,rowsLegs,legsWidth,legsLength);
}


void mezeek::calcAcelerationX()
{
    if(!acelerationActive){
        t = 0;
        aX = 0;
        n = 0;
    }
    else{
        t = k*n*T;
        aX = x() + velIni*t + 0.5*g*pow(t,2);
        n ++;
    }
}


bool mezeek::getAlive() const
{
    return alive;
}

void mezeek::setAlive(bool newAlive)
{
    alive = newAlive;
}

void mezeek::mergeSprites()
{
    const float scale = 2.5;
    QPixmap combinedPixmap(legs->size());
    combinedPixmap.fill(Qt::transparent);
    QPainter painter(&combinedPixmap);
    painter.drawPixmap(0, 0, *legs);
    painter.drawPixmap(0, 0, *torso);
    painter.end();
    combinedPixmap = combinedPixmap.scaled(combinedPixmap.width() * scale,combinedPixmap.height() * scale);
    setPixmap(combinedPixmap);
}


void mezeek::animation()
{
    const float scale = 2.5;
    splitSprite();
    updateSprite();


    if(lying){
        setPixmap(lyingSprite->scaled(lyingSprite->width() * scale, lyingSprite->height() * scale));
    }
    else if(alive && movementActive){
        mergeSprites();
    }
    else if(!movementActive && alive){
        setPixmap(torso->scaled(torso->width() * scale, torso->height() * scale));
    }
    else if(!alive){
        setPixmap(dead->scaled(dead->width() * scale, dead->height() * scale));
    }
}


bool mezeek::detectCollision()
{
    CollidingItems = collidingItems();
    for(int i = 0; i< CollidingItems.size(); i++){
        if(typeid(*CollidingItems[i]) == typeid(rick)){
            return true;
        }
    }
    return false;
}

void mezeek::attack()
{
    bool state = detectCollision();
    if(state == true){
        qDebug() << "Ataque";
        emit killRick();
    }
}


bool mezeek::getConfirmation() const
{
    return confirmation;
}

void mezeek::setConfirmation(bool newConfirmation)
{
    confirmation = newConfirmation;
}

bool mezeek::getMovementActive() const
{
    return movementActive;
}

void mezeek::setMovementActive(bool newMovementActive)
{
    movementActive = newMovementActive;
}

float mezeek::getAX() const
{
    return aX;
}
float mezeek::getT() const
{
    return T;
}

bool mezeek::getAcelerationActive() const
{
    return acelerationActive;
}

void mezeek::setAcelerationActive(bool newAcelerationActive)
{
    acelerationActive = newAcelerationActive;
}

bool mezeek::getLying() const
{
    return lying;
}

void mezeek::setLying(bool newLying)
{
    lying = newLying;
}
