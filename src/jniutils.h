#ifndef JNIUTILS_H
#define JNIUTILS_H

#include <QObject>
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>

class JNIUtils : public QObject
{
    Q_OBJECT
public:
    explicit JNIUtils(QObject *parent = 0);

    static QString jstringToQString(jstring string);
    static QString getServiceString(const QString &service);
};

#endif // JNIUTILS_H
