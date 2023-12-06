#ifndef TEXT_H
#define TEXT_H

#include <QGraphicsItemGroup>
#include <QBrush>
#include <QFont>

class text: public QGraphicsItemGroup
{

private:
    QGraphicsTextItem* textItem;
    QGraphicsTextItem* textItem2;


    QFont customFont;
    QFont customFont2;

public:
    text();
    text(QString text, int size, QString typeFont);
    void changeText(QString newText);
};

#endif // TEXT_H
