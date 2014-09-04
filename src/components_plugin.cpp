#include "components_plugin.h"

#include <qqml.h>

#include "connectivitymanager.h"
#include "downloadmanager.h"
#include "updatechecker.h"
#include "screenvalues.h"

static QObject *screen_values_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    ScreenValues *screenValues = new ScreenValues();
    return screenValues;
}

void ComponentsPlugin::registerTypes(const char *uri)
{
    // @uri com.iktwo.components
    qmlRegisterType<ConnectivityManager>(uri, 1, 0, "ConnectivityManager");
    qmlRegisterType<DownloadManager>(uri, 1, 0, "DownloadManager");
    qmlRegisterType<UpdateChecker>(uri, 1, 0, "UpdateChecker");
    qmlRegisterSingletonType<ScreenValues>(uri, 1, 0, "ScreenValues", screen_values_provider);
}
