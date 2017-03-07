#ifndef DASHITEM_H
#define DASHITEM_H
#include "common.h"
#include "data.h"
//!1
class DashItem: public QGraphicsObject
{
public:
    DashItem(QGraphicsItem *parent=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,QWidget *widget);
    QPixmap DashPix;
};

//!2
class BackgroundItem: public QGraphicsObject
{
public:
    BackgroundItem(QGraphicsItem *parent=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,QWidget *widget);
    QPixmap BackGPix;
    bool BackKey;
    int AllData=0;
protected:
    void timerEvent(QTimerEvent *event);

};




#endif // DASHITEM_H
