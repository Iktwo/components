TEMPLATE = lib
TARGET = components

QT += qml quick

android {
    QT += androidextras

    SOURCES += \
        src/jniutils.cpp

    HEADERS += \
        src/jniutils.h
}

CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.iktwo.components

SOURCES += \
    src/components_plugin.cpp \
    src/screenvalues.cpp \
    src/updatechecker.cpp \
    src/connectivitymanager.cpp \
    src/packagemanager.cpp \
    src/downloadmanager.cpp

HEADERS += \
    src/components_plugin.h \
    src/screenvalues.h \
    src/updatechecker.h \
    src/connectivitymanager.h \
    src/packagemanager.h \
    src/downloadmanager.h

OTHER_FILES = qmldir \
    qml/ImageButton.qml \
    qml/ItemHighlighter.qml \
    qml/Page.qml \
    qml/SubtractMask.qml \
    qml/Theme.qml \
    qml/TitleBar.qml \
    README.md \
    components.qmltypes

qmlfiles.path = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)/qml
qmlfiles.files += $$files(qml/*)

plugininfo.path = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)/
plugininfo.files += components.qmltypes

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.files += qmldir
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir qmlfiles plugininfo
}
