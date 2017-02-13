#ifndef DATA_H
#define DATA_H

#include "common.h"
#include "test_def.h"
#include <pthread.h>


static pthread_mutexattr_t attr;
static pthread_mutex_t d_tw_mutex;

typedef struct
{
    /* warning status */
    telltWarn_data_t telltaleWarnText;
//	warntext_data_t warning_text;
} rc_data_telltWarn_t;

void rc_data_mutex_init();

int set_data(rc_msg_t msg);

int get_data(void *data);



#endif // DATA_H
