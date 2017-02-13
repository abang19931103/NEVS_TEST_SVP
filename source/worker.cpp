#include "include/worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
    startTimer(1000);
    qDebug()<<"thread: "<<QThread::currentThreadId();
}

void Worker::timerEvent(QTimerEvent *event)
{

    threadnum=rand()%69;
    unsigned char i,size;
    size=MAX_WT_GROUP;

    for(i=0;i<size;i++)
    {
         tw_rc_msg.msg_data.tellt_warn_data.icon_status[i]=threadnum+i;
         //qDebug()<<"threadnum:"<<tw_rc_msg.msg_data.tellt_warn_data.icon_status[i];
    }
    //set_data(tw_rc_msg);
}
