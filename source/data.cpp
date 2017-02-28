#include "include/data.h"

static rc_data_telltWarn_t tw_data;
static bool key_value;
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

    switch (msg.msg_type) {
    case RC_MSG_TYPE_TELLT_WT:
        pthread_mutex_lock(&d_tw_mutex);
        tw_data.telltaleWarnText = msg.msg_data.tellt_warn_data;
        result  = 0;
        pthread_mutex_unlock(&d_tw_mutex);
        break;

    case RC_MSG_TYPE_KEY_INFO:
        pthread_mutex_lock(&d_tw_mutex);
        tw_data.telltaleWarnText = msg.msg_data.tellt_warn_data;
        key_value=1;
        result  = 0;	/*mark here add it to msg_queue*/
        qDebug()<<"Set Key Value";
        pthread_mutex_unlock(&d_tw_mutex);
        break;

    default:
        break;
    }

    return result;
}


int get_data(void *data, rc_msg_data_type_t msg_type)
{
    int result = -1;

    switch (msg_type) {
    case RC_MSG_TYPE_TELLT_WT:
        pthread_mutex_lock(&d_tw_mutex);
        *((rc_data_telltWarn_t *)data) = tw_data;
        result  = 0;
        pthread_mutex_unlock(&d_tw_mutex);
        break;
    case RC_MSG_TYPE_KEY_INFO:
        pthread_mutex_lock(&d_tw_mutex);
        if(key_value)
        {
            *((rc_data_telltWarn_t *)data) = tw_data;
            key_value=0;
            result  = 0;
        }
        pthread_mutex_unlock(&d_tw_mutex);
        break;
    default:
        break;
    }
    return result;
}
