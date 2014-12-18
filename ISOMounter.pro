TARGET = ISOMounter

LIBS += \
    -lavkon \
    -lapgrfx \
    -lapmime \
    -lcone \
    -laknnotify \
    -lcentralrepository

TARGET.EPOCHEAPSIZE = 0x40000 0x4000000

TARGET.UID3 = 0xE2051993

DEPLOYMENT += my_deployment
my_deployment.pkg_prerules += vendorinfo
vendorinfo += "%{\"huellif\"}" ":\"huellif\""
VERSION = 1.0.0

RESOURCES += \
    qml.qrc

QT += declarative

{SOURCES += qml/*.qml}

SOURCES += \
    src/QCenRep.cpp \
    src/main.cpp \
    src/helper.cpp

DEFINES += QT_USE_FAST_CONCATENATION QT_USE_FAST_OPERATOR_PLUS QT_NO_CAST_TO_ASCII
DEFINES *= QT_USE_QSTRINGBUILDER

OTHER_FILES += qml/*.*

QMAKE_CXXFLAGS += -std=c++0x
CONFIG += c++11

MMP_RULES += "OPTION gcce -O3"
MMP_RULES += "OPTION gcce -march=armv6"
MMP_RULES += "OPTION gcce -mfpu=vfp"
MMP_RULES += "OPTION gcce -mfloat-abi=softfp"
MMP_RULES += "OPTION gcce -marm"
MMP_RULES += "OPTION gcce -fpermissive"
#MMP_RULES += "OPTION gcce -w"
MMP_RULES += "OPTION gcce -ffast-math"
MMP_RULES += "OPTION gcce -Wno-unused-parameter"
MMP_RULES += "OPTION gcce -std=gnu++0x"

HEADERS += \
    inc/QCenRep.h \
    inc/helper.h
