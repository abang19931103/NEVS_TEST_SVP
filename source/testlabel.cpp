#include "include/testlabel.h"


TestLable::TestLable()
{
    Intnum=20;


    QFont font;
    font.setFamily(QStringLiteral("Consolas"));
    font.setPointSize(30);
    font.setBold(true);
    font.setWeight(75);//设置字体间距
    font.setStyleStrategy(QFont::PreferAntialias);//消除锯齿
    setFont(font);


    //setText(Stringnum);
    setAlignment(Qt::AlignLeft);//设置左对齐

    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::white);
    setPalette(palette);
    setAttribute(Qt::WA_TranslucentBackground);//设置label的背景色为透明

    startTimer(1000);
}

void TestLable::timerEvent(QTimerEvent *event)
{

}

