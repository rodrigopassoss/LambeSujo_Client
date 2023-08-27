# Qt libs to import
QT += core    \
      gui     \
      widgets \
      network \
      opengl  \
      serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TEMPLATE = app
DESTDIR  = ../bin
TARGET   = LambeSujo_Client

# Temporary dirs
OBJECTS_DIR = tmp/obj
MOC_DIR = tmp/moc
UI_DIR = tmp/moc
RCC_DIR = tmp/rc

# Project libs
LIBS *= -lprotobuf -lQt5Core -lGLU -lQt5OpenGL -lQt5Widgets -lQt5Network -lQt5Gui -lQt5SerialPort

# Compiling .proto files
system(echo "Compiling protobuf files" && cd proto && protoc --cpp_out=./ *.proto && cd ../..)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Communication.cpp \
    constants/constants.cpp \
    filters/kalman/kalmanfilter.cpp \
    filters/kalman/matrix/matrix.cpp \
    filters/kalman/state/kalmanstate.cpp \
    filters/loss/lossfilter.cpp \
    filters/noise/noisefilter.cpp \
    main.cpp \
    mainwindow.cpp \
    proto/command.pb.cc \
    proto/common.pb.cc \
    proto/messages_robocup_ssl_detection.pb.cc \
    proto/messages_robocup_ssl_geometry.pb.cc \
    proto/packet.pb.cc \
    proto/replacement.pb.cc \
    proto/vssref_command.pb.cc \
    proto/vssref_common.pb.cc \
    proto/vssref_placement.pb.cc \
    proto/wrapper.pb.cc \
    refereeclient.cpp \
    utils/exithandler/exithandler.cpp \
    utils/qcustomplot.cpp \
    utils/text/text.cpp \
    utils/timer/timer.cpp \
    utils/types/angle/angle.cpp \
    utils/types/field/field.cpp \
    utils/types/object/object.cpp \
    utils/types/placedata/placedata.cpp \
    utils/types/position/position.cpp \
    utils/types/velocity/velocity.cpp \
    utils/utils.cpp \
    vision.cpp

HEADERS += \
    Communication.h \
    constants/constants.h \
    filters/kalman/kalmanfilter.h \
    filters/kalman/matrix/matrix.h \
    filters/kalman/state/kalmanstate.h \
    filters/loss/lossfilter.h \
    filters/noise/noisefilter.h \
    mainwindow.h \
    proto/command.pb.h \
    proto/common.pb.h \
    proto/messages_robocup_ssl_detection.pb.h \
    proto/messages_robocup_ssl_geometry.pb.h \
    proto/packet.pb.h \
    proto/replacement.pb.h \
    proto/vssref_command.pb.h \
    proto/vssref_common.pb.h \
    proto/vssref_placement.pb.h \
    proto/wrapper.pb.h \
    refereeclient.h \
    utils/exithandler/exithandler.h \
    utils/qcustomplot.h \
    utils/text/text.h \
    utils/timer/timer.h \
    utils/types/angle/angle.h \
    utils/types/field/field.h \
    utils/types/field/field_default_3v3.h \
    utils/types/field/field_default_5v5.h \
    utils/types/messagetype/messagetype.h \
    utils/types/object/object.h \
    utils/types/placedata/placedata.h \
    utils/types/position/position.h \
    utils/types/velocity/velocity.h \
    utils/utils.h \
    vision.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recurso.qrc
