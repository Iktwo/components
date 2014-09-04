#include "connectivitymanager.h"

#include "packagemanager.h"
#ifdef Q_OS_ANDROID
#include "jniutils.h"
#endif

#include <QDebug>

#ifdef Q_OS_ANDROID
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
#endif

const char *NetworkStateAccessPermission = "android.permission.ACCESS_NETWORK_STATE";

ConnectivityManager::ConnectivityManager(QObject *parent) :
    QObject(parent)
{
    m_connectionType = retrieveConnectionType();
}

QString ConnectivityManager::retrieveConnectionType()
{
#ifdef Q_OS_ANDROID
    QAndroidJniEnvironment env;
    env->PushLocalFrame(16);
    QAndroidJniObject activity = QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative",
                                                                           "activity",
                                                                           "()Landroid/app/Activity;");

    if (!PackageManager::hasPermission(NetworkStateAccessPermission)) {
        qWarning() << "Package has no permission to access NetworkState, please add " + QString(NetworkStateAccessPermission);
        return "";
    }

    jclass activityClass = env->GetObjectClass(activity.object<jobject>());

    QAndroidJniObject jconnectivityServiceString = QAndroidJniObject::fromString(JNIUtils::getServiceString("CONNECTIVITY_SERVICE"));


    jmethodID mIDGetApplicationContext = env->GetMethodID(activityClass,
                                                          "getApplicationContext",
                                                          "()Landroid/content/Context;");

    jobject appContext = env->CallObjectMethod(activity.object<jobject>(),
                                               mIDGetApplicationContext);

    jclass appContextClass = env->GetObjectClass(appContext);

    jmethodID mIDGetSystemService = env->GetMethodID(appContextClass,
                                                     "getSystemService",
                                                     "(Ljava/lang/String;)Ljava/lang/Object;");

    jobject connectivityManager = env->CallObjectMethod(appContext,
                                                        mIDGetSystemService,
                                                        jconnectivityServiceString.object<jstring>());

    jclass connectivityManagerClass = env->GetObjectClass(connectivityManager);

    jmethodID mIDGetActiveNetworkInfo = env->GetMethodID(connectivityManagerClass,
                                                         "getActiveNetworkInfo",
                                                         "()Landroid/net/NetworkInfo;");

    jobject activeNetworkInfo = env->CallObjectMethod(connectivityManager,
                                                      mIDGetActiveNetworkInfo);

    jclass networkInfoClass = env->GetObjectClass(activeNetworkInfo);

    jmethodID mIDGetTypeName = env->GetMethodID(networkInfoClass,
                                                "getTypeName",
                                                "()Ljava/lang/String;");

    jstring connectionTypeName = (jstring)env->CallObjectMethod(activeNetworkInfo,
                                                                mIDGetTypeName);

    jboolean jfalse = false;
    QString result = env->GetStringUTFChars(connectionTypeName, &jfalse);

    env->PopLocalFrame(NULL);

    return result;

#else
    return "";
#endif
}

QString ConnectivityManager::connectionType() const
{
    return m_connectionType;
}

void ConnectivityManager::setConnectionType(const QString &connectionType)
{
    if (m_connectionType == connectionType)
        return;

    m_connectionType = connectionType;
    emit connectionTypeChanged();
}
