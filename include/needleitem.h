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
    qreal m_instantaneousFrequency;
    QElapsedTimer m_instantaneousElapsed;
    QPropertyAnimation *animation ;
protected:
    void timerEvent(QTimerEvent *);
private:
    QPixmap NeedlePix;
};

#endif // MYITEM_H
