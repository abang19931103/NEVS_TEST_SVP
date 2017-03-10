#ifndef ALLWIDGET_H
#define ALLWIDGET_H

#include <QObject>
#include <QWidget>
#include "common.h"
#include "needleitem.h"
#include "dashitem.h"
#include "midlabel.h"
#include "lwidget.h"
#include "rwidget.h"
#include "data.h"

//class allwidget : public QWidget
class allwidget : public QObject
{
    Q_OBJECT
public:
    //explicit allwidget(QWidget *parent = 0);
    explicit allwidget (QObject *parent =0);
    QGraphicsScene *scene;
    NeedleItem *Needleitem;
    DashItem *Dashitem;
    BackgroundItem *Background1item;
    CenterLabel *SpeedLabel;
    QGraphicsWidget *GraSpeedLabel;

    LWidget *lwidget;
    QGraphicsWidget *Gralwidget;

    RWidget *rwidget;
    QGraphicsWidget *Grarwidget;

    QGraphicsView *view;



signals:
    void changLabelText_status(int *LabelText);
    void changLabelText_text(int *LabelText);
public slots:

private:

    QThread *Lthread;
    Worker  *worker;
    int AllLabel[8]={
        0,0,0,0,0,0,0,0
    };;
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // ALLWIDGET_H
