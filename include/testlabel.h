#ifndef TESTLABEL_H
#define TESTLABEL_H

#include "common.h"
#include "testlabel.h"


class TestLable :public QLabel
{
    Q_OBJECT
public:
    TestLable();
    QString Stringnum;
    int Intnum;
protected:
    void timerEvent(QTimerEvent *event);
private slots:
};



#endif // TESTLABEL_H
