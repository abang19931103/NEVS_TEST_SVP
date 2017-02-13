#include "include/midlabel.h"
#include "include/common.h"
CenterLabel::CenterLabel()
{

    Intnum=200;

    Stringnum=QString::number(Intnum);
    Stringnum=Stringnum+"\nkm/h";

    QFont font;
    font.setFamily(QStringLiteral("Consolas"));
    font.setPointSize(60);
    font.setBold(true);
    font.setWeight(75);//设置字体间距
    font.setStyleStrategy(QFont::PreferAntialias);//消除锯齿
    setFont(font);
    setText(Stringnum);
    setAlignment(Qt::AlignHCenter);//设置居中对齐

    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::white);
    setPalette(palette);
    setAttribute(Qt::WA_TranslucentBackground);//设置label的背景色为透明

    startTimer(200);
}

void CenterLabel::timerEvent(QTimerEvent *event)
{

    ++Intnum;
    if(Intnum>240)
    {
        Intnum=10;
    }
    Stringnum=QString::number(Intnum);
    Stringnum=Stringnum+"\nkm/h";
    setText(Stringnum);
}
