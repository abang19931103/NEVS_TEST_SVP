#include <stdio.h>
#include <pthread.h>

#include <string.h>

#include <include/test_def.h>

#include "SVPWarn.h"
#include "warn/ISVPWarnListener.h"

#include <RCF/RCF.hpp>

#include <QDebug>

#include "include/data.h"

#include "include/message.h"

//extern void rc_message_init_CPP(void);



class SVPWarnListener : public ISVPWarnListener
{
public:
    SVPWarnListener(){}
    virtual ~SVPWarnListener(){}

    virtual SVPVoid SetWarnLEDState(std::vector<SVPUint8> &warnled)
    {
        unsigned char i,size;
        size = (warnled.size() < MAX_TELLT_GROUP) ? warnled.size():MAX_TELLT_GROUP;

        for(i = 0; i < size; i++)
        {
            tw_rc_msg.msg_data.tellt_warn_data.icon_status[i] = warnled.at(i);
        }
        tw_rc_msg.msg_type = RC_MSG_TYPE_KEY_INFO;
        qDebug()<<"warnled["<<i<<"]:"<<tw_rc_msg.msg_data.tellt_warn_data.icon_status[i];
        set_data(tw_rc_msg);
    }

    virtual SVPVoid SetWarnText(std::vector<SVPUint8> & warntext)
    {
        unsigned char i,size;
        size = ((warntext.size()<MAX_WT_GROUP) ? warntext.size():MAX_WT_GROUP);

        for(i = 0; i < size; i++)
        {
            tw_rc_msg.msg_data.tellt_warn_data.warn_text[i] = warntext.at(i);
            //qDebug()<<"warntext["<<i<<"]:"<<tw_rc_msg.msg_data.tellt_warn_data.warn_text[i];
        }
        tw_rc_msg.msg_type = RC_MSG_TYPE_TELLT_WT;
        set_data(tw_rc_msg);
    }
private:
    rc_msg_t tw_rc_msg;
};


SVPWarnListener warn_listener;
ISVPWarnService* pWarnService;

void rc_rcf_init(void)
{
    RCF::init();

    pWarnService = SVP_GetWarnService();	// create an instance
    while(pWarnService->StartService() == false);
    pWarnService->AddListener(&warn_listener);
}

void rc_message_init_CPP(void)
{

    qDebug()<<"rcf init start";
    rc_rcf_init();
    qDebug()<<"rcf init success";

}


