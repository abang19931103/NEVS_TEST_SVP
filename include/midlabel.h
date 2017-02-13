#ifndef MYLABEL_H
#define MYLABEL_H

#include "common.h"


class CenterLabel :public QLabel
{
public:
    CenterLabel();
    QString Stringnum;
    int Intnum;
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // MYLABEL_H
