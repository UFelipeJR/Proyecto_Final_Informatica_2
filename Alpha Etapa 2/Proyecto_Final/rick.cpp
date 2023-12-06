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

    torsoWidth = 33;
    torsoLength = 32;

    rowsTorso = 0;
    columnsTorso = 0;

    rowsLegs = 0;
    columnsLegs = 0;

    rowsWeapon = 0;
    columnsWeapon = 0;

    mass = 70;

    timer->start(60);

    punch = new QSoundEffect(this);
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
    delete punch;
}


bool rick::detectCollision()
{
    CollidingItems = collidingItems();
    for(int i = 0; i < CollidingItems.size(); i++){
        if(typeid(*CollidingItems[i]) == typeid(mezeek)){
            return true;
        }
    }
    return false;
}


bool rick::detectCollision(mezeek* specificMezeek)
{
    CollidingItems = collidingItems();
    for(int i = 0; i < CollidingItems.size(); i++){
        if(typeid(*CollidingItems[i]) == typeid(mezeek)){
            mezeek* mezeekItem = dynamic_cast<mezeek*>(CollidingItems[i]);
            if (mezeekItem && mezeekItem == specificMezeek && mezeekItem->getAlive()) {
                return true;
            }
        }
    }
    return false;
}



float rick::getkineticEnergy(float vel)
{
    return 0.5*(mass*pow(vel,2));
}


void rick::updateSprite()
{
    if(movementActive){
        rowsTorso += torsoLength;
        rowsLegs += legsLength;
        rowsWeapon += weaponLength;
    }


    if(rowsWeapon >= SpriteWeaponLength || !activeWeapon){
        rowsWeapon = 0;
    }
    if(rowsTorso >= SpriteTorsoLength || !movementActive){
        rowsTorso = 0;
    }
    if(rowsLegs >= SpriteLegsLength){
        rowsLegs = 0;
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
    if (!punchTimer->isActive()){
        //punch->play();
        punchTimer->start(450);
        activeWeapon = true;
        qDebug() << "Golpe";
    }
}


void rick::stopPunch()
{
    //punch->stop();
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

void rick::emitSound(int typeSound)
{

    if (typeSound == 1) {
        punch->setSource(QUrl::fromLocalFile(resources::punchSound));
    } else if (typeSound == 2) {
        punch->setSource(QUrl::fromLocalFile(resources::killSound));
    }

    punch->play();

}



