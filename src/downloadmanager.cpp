#include "downloadmanager.h"

#ifdef Q_OS_ANDROID
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
#endif

DownloadManager::DownloadManager(QObject *parent) :
    QObject(parent)
{
}

void DownloadManager::download(const QString &url, const QString &name)
{
#ifdef Q_OS_ANDROID
    QAndroidJniEnvironment env;
    env->PushLocalFrame(16);
    QAndroidJniObject activity = QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative",
                                                                           "activity",
                                                                           "()Landroid/app/Activity;");

    jclass activityClass = env->GetObjectClass(activity.object<jobject>());

    jclass contextClass = env->FindClass("android/content/Context");

    jfieldID fIDDownloadService = env->GetStaticFieldID(contextClass,
                                                        "DOWNLOAD_SERVICE",
                                                        "Ljava/lang/String;");

    jstring downloadServiceString = (jstring)env->GetStaticObjectField(contextClass,
                                                                       fIDDownloadService);

    jmethodID mIDGetApplicationContext = env->GetMethodID(activityClass,
                                                          "getApplicationContext",
                                                          "()Landroid/content/Context;");

    jobject appContext = env->CallObjectMethod(activity.object<jobject>(),
                                               mIDGetApplicationContext);

    jclass appContextClass = env->GetObjectClass(appContext);

    jmethodID mIDGetSystemService = env->GetMethodID(appContextClass,
                                                     "getSystemService",
                                                     "(Ljava/lang/String;)Ljava/lang/Object;");

    jobject downloadManager = env->CallObjectMethod(appContext,
                                                        mIDGetSystemService,
                                                        downloadServiceString);

    jclass downloadManagerClass = env->GetObjectClass(downloadManager);

//    jmethodID mIDGetActiveNetworkInfo = env->GetMethodID(downloadManagerClass,
//                                                         "getActiveNetworkInfo",
//                                                         "()Landroid/net/NetworkInfo;");

//    jobject activeNetworkInfo = env->CallObjectMethod(connectivityManager,
//                                                      mIDGetActiveNetworkInfo);

//    jclass networkInfoClass = env->GetObjectClass(activeNetworkInfo);

//    jmethodID mIDGetTypeName = env->GetMethodID(networkInfoClass,
//                                                "getTypeName",
//                                                "()Ljava/lang/String;");

//    jstring connectionTypeName = (jstring)env->CallObjectMethod(activeNetworkInfo,
//                                                                mIDGetTypeName);
    env->PopLocalFrame(NULL);
#else
    Q_UNUSED(url)
    Q_UNUSED(name)
#endif
}
