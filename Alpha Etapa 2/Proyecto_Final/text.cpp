#include "text.h"

text::text()
{

}

text::text(QString text, int size, QString typeFont)
{
    textItem = new QGraphicsTextItem(text);
    textItem2 = new QGraphicsTextItem(text);

    customFont.setPointSize(size);
    customFont.setFamily(typeFont);
    customFont2.setPointSize(size);
    customFont2.setFamily(typeFont);

    textItem->setFont(customFont);
    textItem2->setFont(customFont2);
    textItem->setDefaultTextColor(Qt::white);
    textItem2->setDefaultTextColor(Qt::black);


    textItem2->setPos(7,1);
    addToGroup(textItem2);
    addToGroup(textItem);
}


void text::changeText(QString newText) {
    textItem->setPlainText(newText);
    //textBoundingRect = textItem->boundingRect();
    //QRectF rectBoundingRect = textBoundingRect.adjusted(-margin, -margin, margin, margin);
    //rectItem->setRect(rectBoundingRect);
    //prepareGeometryChange();
}
