#include "include/data.h"

static rc_data_telltWarn_t tw_data;

void rc_data_mutex_init()
{
    char result;
    result=pthread_mutex_init(&d_tw_mutex,&attr);
    if(result !=0)
    {
        qDebug()<<"Create mutex have error!";
    }
}

int set_data(rc_msg_t msg)
{
    int result = -1;
    pthread_mutex_lock(&d_tw_mutex);
    tw_data.telltaleWarnText = msg.msg_data.tellt_warn_data;
    result  = 0;	/*mark here add it to msg_queue*/
    pthread_mutex_unlock(&d_tw_mutex);
    return result;
}


int get_data( void *data)
{
    int result = -1;
    pthread_mutex_lock(&d_tw_mutex);
    *((rc_data_telltWarn_t *)data) = tw_data;
    result  = 0;
    pthread_mutex_unlock(&d_tw_mutex);
    return result;
}
