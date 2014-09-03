#include "jniutils.h"

JNIUtils::JNIUtils(QObject *parent) :
    QObject(parent)
{
}

QString JNIUtils::jstringToQString(jstring string)
{
    QAndroidJniEnvironment env;
    env->PushLocalFrame(2);

    jboolean jfalse = false;
    QString result = env->GetStringUTFChars(string, &jfalse);

    env->PopLocalFrame(NULL);

    return result;
}

QString JNIUtils::getServiceString(const QString &service)
{
    QAndroidJniEnvironment env;
    env->PushLocalFrame(16);

    jclass contextClass = env->FindClass("android/content/Context");

    jfieldID fIDService = env->GetStaticFieldID(contextClass,
                                                service.toLatin1().constData(),
                                                "Ljava/lang/String;");

    jstring serviceString = (jstring)env->GetStaticObjectField(contextClass,
                                                               fIDService);
    QString result = jstringToQString(serviceString);

    env->PopLocalFrame(NULL);

    return result;
}
