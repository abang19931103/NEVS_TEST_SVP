#include "include/rwidget.h"

RWidget::RWidget(QWidget *parent) : QWidget(parent)
{
    RLayout=new QVBoxLayout(this);
    int i;
    for(i=0;i<8;i++)
    {
        RLabel[i]=new TestLable;
        RLabel[i]->setText("Right Label\t"+QString::number(i));
        RLayout->addWidget(RLabel[i]);
        Labeldata[i]=0;
    }
    setAttribute(Qt::WA_TranslucentBackground);//设置label的背景色为透明


}

void RWidget::Update_RWiaget_data(int *RLabel_data)
{
    //qDebug()<<"Right Label is changed!";
    //int i;
    /*
    for(i=0;i<8;i++)
    {
        RLabel[i]->setText("Right Label\t"+QString::number(RLabel_data[i]));
        //qDebug()<<"Right Label is :"<<RLabel_data[i+4];
    }
    */
    //bool ok;
    int IOCalc;
    IOCalc=((char)RLabel_data[1]<<8)+RLabel_data[0];
    RLabel[0]->setText("IO Label is :"+QString::number(IOCalc,2));

    int IKL30Calc;
    IKL30Calc=((char)RLabel_data[3]<<8)+RLabel_data[2];
    RLabel[1]->setText("KL30 Label is :"+QString::number(IKL30Calc));


    int IKLX1Calc;
    IKLX1Calc=((char)RLabel_data[5]<<8)+RLabel_data[4];
    RLabel[2]->setText("KLX1 Label is :"+QString::number(IKLX1Calc));

    int IKLX2Calc;
    IKLX2Calc=((char)RLabel_data[7]<<8)+RLabel_data[6];
    RLabel[3]->setText("KLX2 Label is :"+QString::number(IKLX2Calc));

    RLabel[4]->setText("KL30_low8bit "+QString::number(RLabel_data[2]));
    RLabel[5]->setText("KL30_high3bit "+QString::number(RLabel_data[3]));
}

