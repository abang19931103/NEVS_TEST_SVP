INCLUDEPATH += /home/sv/sv-g5-cluster-application/platform-sdk/arm/include

LIBS+= -L/home/sv/sv-g5-cluster-application/platform-sdk/arm/lib -lwarn_rcf -lRCF -lsource -lservice -lbasic

RESOURCES += \
    image.qrc

HEADERS += \
    include/allwidget.h \
    include/common.h \
    include/dashitem.h \
    include/lwidget.h \
    include/midlabel.h \
    include/needleitem.h \
    include/rwidget.h \
    include/test_def.h \
    include/testlabel.h \
    include/worker.h \
    include/data.h \
    include/isvptriplistener.h \
    include/message.h

SOURCES += \
    source/allwidget.cpp \
    source/dashitem.cpp \
    source/lwidget.cpp \
    source/main.cpp \
    source/middlabel.cpp \
    source/needleitem.cpp \
    source/rwidget.cpp \
    source/testlabel.cpp \
    source/worker.cpp \
    source/data.cpp \
    source/message.cpp
QT += widgets




