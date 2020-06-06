#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnipj_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */,
        jstring jstring1) {
    jboolean isCopy= static_cast<jboolean>(false);
    jchar* s= const_cast<jchar *>(env->GetStringChars(jstring1, &isCopy));
    size_t size= static_cast<size_t>((env)->GetStringLength(jstring1));
    for(int i=0;i<size;i++){
        s[i]++;
    }
    env->ReleaseStringChars(jstring1,s);
    return env->NewString(s,size);
}


