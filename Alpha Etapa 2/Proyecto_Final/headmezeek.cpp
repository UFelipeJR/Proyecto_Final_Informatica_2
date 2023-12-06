#include "headmezeek.h"

headMezeek::headMezeek()
{
    head.load(":/Resources/Sprites/Mezeek/mezeekHead.png");
    head = head.scaled(head.width() * 0.2, head.height() * 0.2);
    setPixmap(head);

    x = 0;
    y = 0;
    xo = 0;
    yo = 0;
    vxo = 0;
    vyo = 0;
    g = 9.81;
}

headMezeek::headMezeek(float xo, float yo, float vxo, float vyo)
{
    head.load(":/Resources/Sprites/Mezeek/mezeekHead.png");
    head = head.scaled(head.width() * 0.2, head.height() * 0.2);
    setPixmap(head);

    this->xo = xo;
    this->yo = yo;
    this->vxo = vxo;
    this->vyo = vyo;
}

float headMezeek::posX(float t)
{
    return xo+vxo*t;
}

float headMezeek::posY(float t)
{
    return yo-vyo*t+0.5*g*t*t;
}
