SOURCES = main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtbase/statemachine/trafficlight
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS trafficlight.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/qtbase/statemachine/trafficlight
INSTALLS += target sources
QT += widgets

symbian: CONFIG += qt_example
maemo5: CONFIG += qt_example

