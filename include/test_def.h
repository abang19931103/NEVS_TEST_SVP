#ifndef TEST_DEF_H
#define TEST_DEF_H
#include <stdint.h>

#define MAX_TELLT_GROUP			8
#define MAX_WT_GROUP			8

typedef struct
{
    int icon_status[MAX_TELLT_GROUP];

    int warn_text[MAX_WT_GROUP];
}telltWarn_data_t;

typedef union
{
    telltWarn_data_t tellt_warn_data;
}rc_msg_data_t;


typedef struct
{
    //rc_msg_data_type_t msg_type;
    rc_msg_data_t msg_data;
}rc_msg_t;


#endif // TEST_DEF_H
