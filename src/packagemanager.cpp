#include "packagemanager.h"

#ifdef Q_OS_ANDROID
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
#endif

PackageManager::PackageManager(QObject *parent) :
    QObject(parent)
{
}

bool PackageManager::hasPermission(const QString &permission)
{
#ifdef Q_OS_ANDROID
    QAndroidJniEnvironment env;
    env->PushLocalFrame(15);
    QAndroidJniObject activity = QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative",
                                                                           "activity",
                                                                           "()Landroid/app/Activity;");
    jclass activityClass = env->GetObjectClass(activity.object<jobject>());

    jmethodID mIDGetPackageName = env->GetMethodID(activityClass,
                                                   "getPackageName",
                                                   "()Ljava/lang/String;");

    jstring packageName = (jstring)env->CallObjectMethod(activity.object<jobject>(),
                                                         mIDGetPackageName);

    jmethodID mIDGetPackageManager = env->GetMethodID(activityClass,
                                                      "getPackageManager",
                                                      "()Landroid/content/pm/PackageManager;");

    jobject packageManager = env->CallObjectMethod(activity.object<jobject>(),
                                                   mIDGetPackageManager);

    jclass packageManagerClass = env->GetObjectClass(packageManager);

    jclass packageManagerStaticClass = env->FindClass("android/content/pm/PackageManager");

    jfieldID fIDPermissionGranted = env->GetStaticFieldID(packageManagerStaticClass,
                                                          "PERMISSION_GRANTED",
                                                          "I");

    jint PERMISSION_GRANTED = env->GetStaticIntField(packageManagerStaticClass,
                                                     fIDPermissionGranted);

    jmethodID mIDCheckPermission = env->GetMethodID(packageManagerClass,
                                                    "checkPermission",
                                                    "(Ljava/lang/String;Ljava/lang/String;)I");

    QAndroidJniObject jpermission = QAndroidJniObject::fromString(permission);

    int jresult = (int)env->CallIntMethod(packageManager, mIDCheckPermission, jpermission.object<jstring>(), packageName);
    bool result = jresult == PERMISSION_GRANTED;

    env->PopLocalFrame(NULL);

    return result;
#else
    Q_UNUSED(permission)
    return false;
#endif
}
