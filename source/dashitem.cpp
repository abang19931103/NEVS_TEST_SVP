#include "include/dashitem.h"
#include "include/common.h"
//!1
DashItem::DashItem(QGraphicsItem *parent)
{
    DashPix.load(":/Image/Image/Dashboard.png");

    Q_UNUSED(parent);
}

QRectF DashItem::boundingRect() const
{
    return QRectF(-310,-310,620,620);
}

void DashItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(-310,-310,DashPix.width(),DashPix.height(),DashPix);
}

//!2
BackgroundItem::BackgroundItem(QGraphicsItem *parent)
{
    Q_UNUSED(parent);
    BackKey=1;
    BackGPix.load(":/Image/Image/bg_1_1.png");
    startTimer(100);
}

QRectF BackgroundItem::boundingRect() const
{
    return QRectF(-960,-360,1920,720);
}

void BackgroundItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    /*
    if(BackKey)
    {
        BackGPix.load(":/Image/Image/bg_1_1.png");
        painter->drawPixmap(-960,-360,BackGPix.width(),BackGPix.height(),BackGPix);
    }
    else
    {
        BackGPix.load(":/Image/Image/bg2.png");
        painter->drawPixmap(-960,-360,BackGPix.width(),BackGPix.height(),BackGPix);
    }
    */
    painter->drawPixmap(-960,-360,BackGPix.width(),BackGPix.height(),BackGPix);

}


void BackgroundItem::timerEvent(QTimerEvent *event)
{
    rc_data_telltWarn_t tw_data;

    if(0==get_data(&tw_data,RC_MSG_TYPE_KEY_INFO))
    {
        //qDebug()<<"Key !"<< tw_data.telltaleWarnText.icon_status[0];

        if(AllData!=tw_data.telltaleWarnText.icon_status[0])
        {
            //tw_data.telltaleWarnText.icon_status[0]=0;

            BackKey=!BackKey;
            if(BackKey)
            {
                BackGPix.load(":/Image/Image/bg_1_1.png");
            }
            else
            {
                BackGPix.load(":/Image/Image/bg2.png");
            }
            update();
            //qDebug()<<"Key Value Change!"<< tw_data.telltaleWarnText.icon_status[0];
        }
    }

}

