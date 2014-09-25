#ifndef APPLICATIONINFO_H
#define APPLICATIONINFO_H

#include <QObject>
#include <QDate>

class ApplicationInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int timesLaunched READ timesLaunched NOTIFY timesLaunchedChanged)
    Q_PROPERTY(QDate firstTimeLaunched READ firstTimeLaunched NOTIFY firstTimeLaunchedChanged)
    Q_PROPERTY(bool hasShownInitialDialog READ hasShownInitialDialog WRITE setHasShownInitialDialog NOTIFY hasShownInitialDialogChanged)

public:
    explicit ApplicationInfo(QObject *parent = 0);

    int timesLaunched() const;
    void setTimesLaunched(int timesLaunched);

    QDate firstTimeLaunched() const;
    void setFirstTimeLaunched(const QDate &firstTimeLaunched);

    bool hasShownInitialDialog() const;
    void setHasShownInitialDialog(bool hasShownInitialDialog);

signals:
    void timesLaunchedChanged();
    void firstTimeLaunchedChanged();
    void hasShownInitialDialogChanged();

private:
    int m_timesLaunched;
    QDate m_firstTimeLaunched;
    bool m_hasShownInitialDialog;

};

#endif // APPLICATIONINFO_H
