TEMPLATE = lib
TARGET = components
QT += qml quick
CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.iktwo.components

SOURCES += \
    src/components_plugin.cpp \
    src/screenvalues.cpp

HEADERS += \
    src/components_plugin.h \
    src/screenvalues.h

OTHER_FILES = qmldir \
    qml/ImageButton.qml \
    qml/Page.qml \
    qml/Theme.qml \
    qml/TitleBar.qml \
    README.md \
    plugins.qmltype

qmlfiles.path = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)/qml
qmlfiles.files += $$files(qml/*)

plugininfo.path = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)/
plugininfo.files += plugins.qmltype

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
