#include "include/allwidget.h"
#include "include/message.h"
//extern void rc_message_init_CPP();
int main(int argc,char * argv[])
{
    QApplication app(argc,argv);

    rc_data_telltWarn_t();
    rc_message_init_CPP();

    allwidget w;

    w.show();

    return app.exec();
}
