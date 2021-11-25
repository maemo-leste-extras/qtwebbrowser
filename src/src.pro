TARGET = qtwebbrowser

CONFIG += c++11
CONFIG -= app_bundle

SOURCES = \
    appengine.cpp \
    main.cpp \
    mceinputmethodfilter.cpp \
    navigationhistoryproxymodel.cpp \
    touchtracker.cpp

HEADERS = \
    appengine.h \
    mceinputmethodfilter.h \
    navigationhistoryproxymodel.h \
    touchtracker.h \

OTHER_FILES = \
    qml/assets/UIButton.qml \
    qml/assets/UIToolBar.qml \
    qml/ApplicationRoot.qml \
    qml/BrowserWindow.qml \
    qml/FeaturePermissionBar.qml \
    qml/MockTouchPoint.qml \
    qml/PageView.qml \
    qml/NavigationBar.qml \
    qml/HomeScreen.qml \
    qml/SettingsView.qml \
    qml/Keyboard.qml \
    qml/Window.qml

QT += qml quick webengine dbus

RESOURCES += resources.qrc

DEFINES += DESKTOP_BUILD
QT += gui-private
isEmpty(INSTALL_PREFIX): INSTALL_PREFIX=/usr/bin

target.path = $$INSTALL_PREFIX
INSTALLS += target
