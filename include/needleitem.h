#ifndef MYITEM_H
#define MYITEM_H
#include "common.h"


class NeedleItem : public QGraphicsObject
{

public:
    NeedleItem(QGraphicsItem *paren=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,QWidget *widget);

    int stdRand;

    QPropertyAnimation *animation ;
protected:
    void timerEvent(QTimerEvent *);
};

#endif // MYITEM_H
