#ifndef PACKAGEMANAGER_H
#define PACKAGEMANAGER_H

#include <QObject>

class PackageManager : public QObject
{
    Q_OBJECT
public:
    explicit PackageManager(QObject *parent = 0);

    Q_INVOKABLE static bool packageHasPermission(const QString &package, const QString &permission);
    Q_INVOKABLE static bool hasPermission(const QString &permission);
};

#endif // PACKAGEMANAGER_H
