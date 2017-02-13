#ifndef LWIDGET_H
#define LWIDGET_H

#include <QWidget>
#include "common.h"
#include "testlabel.h"
#include "worker.h"
#include "test_def.h"
class LWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LWidget(QWidget *parent = 0);

    TestLable * LLabel[8];
    QVBoxLayout *LLayout;
    int Labeldata[8];
signals:

public slots:
    void Update_LWiaget_data(int * LLabel_data);
};

#endif // LWIDGET_H
