#include "include/lwidget.h"
#include "include/data.h"


LWidget::LWidget(QWidget *parent) : QWidget(parent)
{
    LLayout=new QVBoxLayout(this);
    int i;
    for(i=0;i<8;i++)
    {
        LLabel[i]=new TestLable;
        LLabel[i]->setText("Left Label\t"+QString::number(i));
        LLayout->addWidget(LLabel[i]);
        Labeldata[i]=0;
    }

    setAttribute(Qt::WA_TranslucentBackground);//设置label的背景色为透明
}

void LWidget::Update_LWiaget_data(int *LLabel_data)
{
    //qDebug()<<"Left Label is changed!";
    int i;
    for(i=0;i<8;i++)
    {
        LLabel[i]->setText("Left Label\t"+QString::number(LLabel_data[i]));
    }
}
