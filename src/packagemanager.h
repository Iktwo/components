#ifndef PACKAGEMANAGER_H
#define PACKAGEMANAGER_H

#include <QObject>

class PackageManager : public QObject
{
    Q_OBJECT
public:
    explicit PackageManager(QObject *parent = 0);

    static bool hasPermission(const QString &permission);
signals:

public slots:

};

#endif // PACKAGEMANAGER_H
