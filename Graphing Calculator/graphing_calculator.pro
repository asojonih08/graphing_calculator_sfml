TEMPLATE = app
CONFIG += console
#CONFIG -= app_bundle

#since we want to use qDebug, we
#will not subtract qt.
#CONFIG -= qt

CONFIG += c++11
#------------------------------------------
##Add these lines for SFML:



#WINDOWS
# put SFML file in the same location as project
LIBS += -L"..\..\SFML-2.5.1\lib" #change this
LIBS += -L"..\..\SFML-2.5.1\bin" #change this

#MAC
#LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "..\..\SFML-2.5.1\include" #change this
DEPENDPATH  += "..\..\SFML-2.5.1\include" #change this

#MAC
#INCLUDEPATH += "/usr/local/include"
#DEPENDPATH += "/usr/local/include"

#-----------------------------------------

SOURCES += main.cpp \
    animate.cpp \
    coordtranslation.cpp \
    function.cpp \
    graph.cpp \
    graphinfo.cpp \
    input.cpp \
    number.cpp \
    operator.cpp \
    plot.cpp \
    random.cpp \
    rpn.cpp \
    shuntingyard.cpp \
    sidebar.cpp \
    system.cpp \
    token.cpp



HEADERS += \
    LParen.h \
    RParen.h \
    animate.h \
    constants.h \
    coordtranslation.h \
    function.h \
    graph.h \
    graphinfo.h \
    includes/linked_lists.h \
    includes/Queue.h \
    includes/Stack.h \
    input.h \
    number.h \
    operator.h \
    plot.h \
    random.h \
    rpn.h \
    shuntingyard.h \
    sidebar.h \
    system.h \
    token.h \
    variable.h \
    z_output.h \
    z_work_report.h

