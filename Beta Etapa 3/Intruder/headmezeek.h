#ifndef HEADMEZEEK_H
#define HEADMEZEEK_H

#include <QGraphicsPixmapItem>

class headMezeek: public QGraphicsPixmapItem
{

private:
    QPixmap head;
    float xo,yo,vxo,vyo,x,y,g;

public:
    headMezeek();
    headMezeek(float xo, float yo, float vxo, float vyo);
    float posX(float t);
    float posY(float t);
};

#endif // HEADMEZEEK_H
