#include "applicationinfo.h"

#include <QSettings>

ApplicationInfo::ApplicationInfo(QObject *parent) :
    QObject(parent),
    m_timesLaunched(0)
{
    QSettings settings;
    m_timesLaunched = settings.value("timesLaunched", 0).toInt();
    m_firstTimeLaunched = settings.value("firstTimeLaunched", QDate::fromString("20000101", "yyyyMMdd")).toDate();

    if (m_firstTimeLaunched.toString("yyyyMMdd") == "20000101")
        setFirstTimeLaunched(QDate::currentDate());

    setTimesLaunched(m_timesLaunched + 1);
}

int ApplicationInfo::timesLaunched() const
{
    return m_timesLaunched;
}

void ApplicationInfo::setTimesLaunched(int timesLaunched)
{
    if (m_timesLaunched == timesLaunched)
        return;

    m_timesLaunched = timesLaunched;

    QSettings settings;
    settings.setValue("timesLaunched", m_timesLaunched);

    emit timesLaunchedChanged();
}

QDate ApplicationInfo::firstTimeLaunched() const
{
    return m_firstTimeLaunched;
}

void ApplicationInfo::setFirstTimeLaunched(const QDate &firstTimeLaunched)
{
    if (m_firstTimeLaunched == firstTimeLaunched)
        return;

    m_firstTimeLaunched = firstTimeLaunched;

    QSettings settings;
    settings.setValue("firstTimeLaunched", m_firstTimeLaunched);

    emit firstTimeLaunchedChanged();
}
