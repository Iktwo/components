#include "components_plugin.h"
#include "screenvalues.h"

#include <qqml.h>

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
    qmlRegisterSingletonType<ScreenValues>(uri, 1, 0, "ScreenValues", screen_values_provider);
}
