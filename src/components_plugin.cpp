#include "components_plugin.h"

#include <qqml.h>

#include "applicationinfo.h"
#include "connectivitymanager.h"
#include "downloadmanager.h"
#include "packagemanager.h"
#include "updatechecker.h"
#include "screenvalues.h"

static QObject *application_info_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    ApplicationInfo *applicationInfo = new ApplicationInfo();
    return applicationInfo;
}

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
    qmlRegisterType<PackageManager>(uri, 1, 0, "PackageManager");
    qmlRegisterType<UpdateChecker>(uri, 1, 0, "UpdateChecker");
    qmlRegisterSingletonType<ApplicationInfo>(uri, 1, 0, "ApplicationInfo", application_info_provider);
    qmlRegisterSingletonType<ScreenValues>(uri, 1, 0, "ScreenValues", screen_values_provider);
}
