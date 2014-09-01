#ifndef UPDATECHECKER_H
#define UPDATECHECKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class UpdateChecker : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString packageName READ packageName NOTIFY packageNameChanged)
    Q_PROPERTY(QString version READ version NOTIFY versionChanged)
    Q_PROPERTY(QString latestVersion READ latestVersion NOTIFY latestVersionChanged)
public:
    explicit UpdateChecker(QObject *parent = 0);

    Q_INVOKABLE void checkForUpdateOnGooglePlay();
    Q_INVOKABLE void openPackageOnGooglePlay();

    QString packageName() const;
    void setPackageName(const QString &packageName);

    QString version() const;
    void setVersion(const QString &version);

    QString latestVersion() const;
    void setLatestVersion(const QString &latestVersion);

signals:
    void packageNameChanged();
    void versionChanged();
    void latestVersionChanged();
    void errorDownloading();

private:
    QString m_packageName;
    QString m_version;
    QString m_latestVersion;
    QNetworkAccessManager *m_netAccess;

    QString retrievePackageName();
    QString retrieveVersion();

private slots:
    void networkRequestFinished(QNetworkReply *reply);
};

#endif // UPDATECHECKER_H
