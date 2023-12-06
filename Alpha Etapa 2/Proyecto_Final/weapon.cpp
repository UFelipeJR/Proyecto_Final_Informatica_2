#include "weapon.h"

weapon::weapon()
{
    const float scale = 2.5;
    launchActive = false;
    weaponS = new QPixmap();
    time = new QTimer();


    weaponS->load(resources::weaponSprite);
    time->start(0.1 * 100);


    friction = 0.1;
    mass = 15;
    normalForce = 98.1;
    velIni = 10;
    deltaTime = 0.1;
    forceFriction = friction*normalForce;
    vel = velIni;
    aFriction = 0;
    lossSpeed = 0;

    *weaponS = weaponS->scaled(weaponS->width()*scale,weaponS->height()*scale);
    setPixmap(*weaponS);
    connect(time,SIGNAL(timeout()),this,SLOT(movement()));
}

weapon::~weapon()
{
    delete weaponS;
}

void weapon::movement()
{
    if(launchActive && vel >= 0.0){
        aFriction = forceFriction/mass;
        lossSpeed = aFriction*deltaTime;
        vel -= lossSpeed;
    }

    if(vel <= 0.0){
       launchActive = false;
       vel = velIni;
    }

}



bool weapon::detectCollision(mezeek *specificMezeek)
{
    CollidingItems = collidingItems();
    for(int i = 0; i < CollidingItems.size(); i++){
        if(typeid(*CollidingItems[i]) == typeid(mezeek)){
            mezeek* mezeekItem = dynamic_cast<mezeek*>(CollidingItems[i]);
            if (mezeekItem == specificMezeek && mezeekItem->getAlive()) {
                return true;
            }
        }
    }
    return false;
}

bool weapon::getLaunchActive() const
{
    return launchActive;
}

void weapon::setLaunchActive(bool newLaunchActive)
{
    launchActive = newLaunchActive;
}

float weapon::getVel() const
{
    return vel;
}

void weapon::setVel(float newVel)
{
    vel = newVel;
}



