#ifndef APPLICATIONINFO_H
#define APPLICATIONINFO_H

#include <QObject>
#include <QDate>

class ApplicationInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int timesLaunched READ timesLaunched NOTIFY timesLaunchedChanged)
    Q_PROPERTY(QDate firstTimeLaunched READ firstTimeLaunched NOTIFY firstTimeLaunchedChanged)

public:
    explicit ApplicationInfo(QObject *parent = 0);

    int timesLaunched() const;
    void setTimesLaunched(int timesLaunched);

    QDate firstTimeLaunched() const;
    void setFirstTimeLaunched(const QDate &firstTimeLaunched);

signals:
    void timesLaunchedChanged();
    void firstTimeLaunchedChanged();

private:
    int m_timesLaunched;
    QDate m_firstTimeLaunched;

};

#endif // APPLICATIONINFO_H
