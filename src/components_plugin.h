#ifndef COMPONENTS_PLUGIN_H
#define COMPONENTS_PLUGIN_H

#include <QQmlExtensionPlugin>

class ComponentsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // COMPONENTS_PLUGIN_H

