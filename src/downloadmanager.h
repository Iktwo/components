#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QObject>

class DownloadManager : public QObject
{
    Q_OBJECT
public:
    explicit DownloadManager(QObject *parent = 0);

    Q_INVOKABLE void download(const QString &url, const QString &name);
};

#endif // DOWNLOADMANAGER_H
