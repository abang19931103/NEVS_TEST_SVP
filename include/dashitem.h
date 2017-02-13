#ifndef DASHITEM_H
#define DASHITEM_H
#include "common.h"
class DashItem: public QGraphicsObject
{
public:
    DashItem(QGraphicsItem *paren=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,QWidget *widget);
    QPixmap DashPix;
};
class BackgroundItem: public QGraphicsObject
{
public:
    BackgroundItem(QGraphicsItem *parent=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,QWidget *widget);
    QPixmap BackGPix;
};

#endif // DASHITEM_H
