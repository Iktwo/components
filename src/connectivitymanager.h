#ifndef CONNECTIVITYMANAGER_H
#define CONNECTIVITYMANAGER_H

#include <QObject>

class ConnectivityManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString connectionType READ connectionType NOTIFY connectionTypeChanged)
public:
    explicit ConnectivityManager(QObject *parent = 0);

    Q_INVOKABLE QString retrieveConnectionType();

    QString connectionType() const;
    void setConnectionType(const QString &connectionType);

signals:
    void connectionTypeChanged();

private:
    QString m_connectionType;
};

#endif // CONNECTIVITYMANAGER_H
