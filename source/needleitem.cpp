#include "include/needleitem.h"
#include "include/common.h"
NeedleItem::NeedleItem(QGraphicsItem *paren)
{

    animation=new QPropertyAnimation(this,"rotation");
    startTimer(1200);
    animation->setDuration(1000);
    stdRand=0;
    animation->setStartValue(stdRand);
    animation->setEasingCurve(QEasingCurve::OutQuint);
    NeedlePix.load(":/Image/Image/Needle.png");
    //animation->setEasingCurve(QEasingCurve::setPeriod(QEasingCurve::OutQuint));
    //qDebug()<<"animation->setStartValue(0);";
}

QRectF NeedleItem::boundingRect() const
{
    //return QRectF(-45,0,90,300);    //返回要绘制图形项的矩形区域
    return QRectF(-300,-300,600,600);
}

void NeedleItem::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setRenderHint(QPainter::SmoothPixmapTransform);

    painter->rotate(45);

    painter->drawPixmap(-45,0,NeedlePix.width(),NeedlePix.height(),NeedlePix);

    const qint64 ms = m_instantaneousElapsed.restart();
    m_instantaneousFrequency = ms ? qreal(1000) / ms : 0;
    qDebug()<<"FPS:  "<<m_instantaneousFrequency;
}

void NeedleItem::timerEvent(QTimerEvent *event)
{
    animation->start();

    animation->setStartValue(stdRand);
    stdRand=rand()%270;
    //stdRand=270;
    animation->setEndValue(stdRand);
}




