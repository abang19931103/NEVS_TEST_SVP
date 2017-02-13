#ifndef __ISVP_WARN_SERVICE_LISTENER_H__
#define __ISVP_WARN_SERVICE_LISTENER_H__

#include "svptype.h"

#include "warn/svpwarntype.h"

class ISVPWarnListener
{
public:
    virtual ~ISVPWarnListener(){};

    virtual SVPVoid SetWarnLEDState(std::vector<SVPUint8> &warnled) = 0;

    virtual SVPVoid SetWarnText(std::vector<SVPUint8> & warntext) = 0;

};

#endif // __ISVP_WARN_SERVICE_LISTENER_H__
