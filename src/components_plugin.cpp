#include "components_plugin.h"

#include <qqml.h>

#include "screenvalues.h"
#include "updatechecker.h"

static QObject *screen_values_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    ScreenValues *screenValues = new ScreenValues();
    return screenValues;
}

static QObject *update_checker_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    UpdateChecker *updateChecker = new UpdateChecker();
    return updateChecker;
}

void ComponentsPlugin::registerTypes(const char *uri)
{
    // @uri com.iktwo.components
    qmlRegisterSingletonType<ScreenValues>(uri, 1, 0, "ScreenValues", screen_values_provider);
    qmlRegisterSingletonType<UpdateChecker>(uri, 1, 0, "UpdateChecker", update_checker_provider);
}
