#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "common.h"
#include "test_def.h"
#include "data.h"
class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);

protected:
    void timerEvent(QTimerEvent *event);
private:
    int threadnum;
    rc_msg_t tw_rc_msg;
signals:
    void workerdatachanged(rc_msg_t data);

};

#endif // WORKER_H
