############################################################
# Project file for autotest for file qabstractprintdialog.h
############################################################

load(qttest_p4)
QT += widgets printsupport
SOURCES += tst_qabstractprintdialog.cpp

CONFIG += insignificant_test # QTBUG-21402
