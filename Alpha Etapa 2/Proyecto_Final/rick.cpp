#include "rick.h"

rick::rick()
{
    torso = new QPixmap();
    legs = new QPixmap();
    weaponTorso = new QPixmap();
    timer = new QTimer();
    punchTimer = new QTimer();
    dead = new QPixmap();
    movementActive = false;
    activeWeapon = false;
    alive = true;

    weaponWidth = 43;
    weaponLength = 42;

    legsWidth = 33;
    legsLength = 32;

    torsoWidth = 24;
    torsoLength = 33;

    rowsTorso = 0;
    columnsTorso = 0;

    rowsLegs = 0;
    columnsLegs = 0;

    rowsWeapon = 0;
    columnsWeapon = 0;

    timer->start(60);
    connect(timer, SIGNAL(timeout()), this, SLOT(animation()));
    connect(punchTimer, SIGNAL(timeout()),this,SLOT(stopPunch()));
    dead->load(resources::deadRick);

}

rick::~rick()
{
    delete torso;
    delete legs;
    delete timer;
    delete weaponTorso;
    delete punchTimer;
    delete dead;
}


bool rick::detectCollision()
{
    mezeek* mezeekItem;
    CollidingItems = collidingItems();
    for(int i = 0; i < CollidingItems.size(); i++){
        if(typeid(*CollidingItems[i]) == typeid(mezeek)){
            mezeekItem = dynamic_cast<mezeek*>(CollidingItems[i]);
            if (mezeekItem && mezeekItem->getAlive()) {
                return true;
            }
        }
    }
    return false;
}


void rick::updateSprite()
{
    if(movementActive){
        rowsTorso += torsoLength;
        rowsLegs += legsLength;
        rowsWeapon += weaponLength;
    }

    if(rowsTorso >= SpriteTorsoLength || !movementActive){
        rowsTorso = 0;
    }
    if(rowsLegs >= SpriteLegsLength){
        rowsLegs = 0;
    }
    if(rowsWeapon >= SpriteWeaponLength || !activeWeapon){
        rowsWeapon = 0;
    }
}


void rick::splitSprite()
{
    QPixmap torsoAux(resources::torsoRick);
    QPixmap legsAux(resources::legsRick);
    QPixmap weaponAux(resources::weaponRick);
    *torso = torsoAux.copy(columnsTorso,rowsTorso,torsoWidth,torsoLength);
    *legs = legsAux.copy(columnsLegs,rowsLegs,legsWidth,legsLength);
    *weaponTorso = weaponAux.copy(columnsWeapon,rowsWeapon,weaponWidth,weaponLength);
}

void rick::mergeSprites()
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


void rick::animation()
{
    const float scale = 2.5;

    splitSprite();
    updateSprite();


    if(!alive){
        setPixmap(dead->scaled(dead->width() * scale, dead->height() * scale));
    }
    else if(movementActive && !activeWeapon){
        mergeSprites();
    }
    else if(!movementActive){
        setPixmap(torso->scaled(torso->width() * scale, torso->height() * scale));
    }

    if(activeWeapon && alive){
        setPixmap(weaponTorso->scaled(weaponTorso->width() * scale, weaponTorso->height() * scale));
    }

}


void rick::punchRick()
{
    punchTimer->start(450);
    activeWeapon = true;
    qDebug() << "Golpe";

}

void rick::stopPunch()
{
    punchTimer->stop();
    activeWeapon = false;
    movementActive = false;
    qDebug() << "Finalizado";

}


bool rick::getMovementActive() const
{
    return movementActive;
}

void rick::setMovementActive(bool newMovementActive)
{
    movementActive = newMovementActive;
}

bool rick::getActiveWeapon() const
{
    return activeWeapon;
}

void rick::setActiveWeapon(bool newActiveWeapon)
{
    activeWeapon = newActiveWeapon;
}

bool rick::getAlive() const
{
    return alive;
}

void rick::setAlive(bool newAlive)
{
    alive = newAlive;
}


