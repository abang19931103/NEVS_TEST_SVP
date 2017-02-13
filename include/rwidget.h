#ifndef RWIDGET_H
#define RWIDGET_H

#include <QWidget>
#include "common.h"
#include "testlabel.h"
#include "test_def.h"
#include "worker.h"
class RWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RWidget(QWidget *parent = 0);

    TestLable * RLabel[8];
    QVBoxLayout *RLayout;
    int Labeldata[8];
signals:

public slots:
    void Update_RWiaget_data(int * RLabel_data);
private:

};

#endif // RWIDGET_H
