#include "include/dashitem.h"
#include "include/common.h"
DashItem::DashItem(QGraphicsItem *paren)
{

}

QRectF DashItem::boundingRect() const
{
    return QRectF(-310,-310,620,620);
}

void DashItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    DashPix.load(":/Image/Image/Dashboard.png");
    painter->drawPixmap(-310,-310,DashPix.width(),DashPix.height(),DashPix);
}

BackgroundItem::BackgroundItem(QGraphicsItem *parent)
{

}

QRectF BackgroundItem::boundingRect() const
{
    return QRectF(-960,-360,1920,720);
}

void BackgroundItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    BackGPix.load(":/Image/Image/bg_1_1.png");
    painter->drawPixmap(-960,-360,BackGPix.width(),BackGPix.height(),BackGPix);
}
