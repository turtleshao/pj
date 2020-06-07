#include <jni.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/ptrace.h>

#define JNIREG_CLASS "com/example/crackme/MainActivity"
extern "C" JNIEXPORT jstring JNICALL M2358C(
        JNIEnv* env,
        jobject /* this */,
        jstring jstring1) {
    jboolean isCopy= static_cast<jboolean>(false);
    char* s= const_cast<char *>(env->GetStringUTFChars(jstring1, &isCopy));
    size_t size= static_cast<size_t>((env)->GetStringUTFLength(jstring1));
    char r[size+1];
    for(int i=0;i<=size;i++){
        r[i]='\0';
    }
    for(int i=0;i<size;i++){
        r[i]= static_cast<char>(s[i] + 1);
    }
    env->ReleaseStringUTFChars(jstring1,s);
    return env->NewStringUTF(r);
}
extern "C" JNIEXPORT jboolean JNICALL M2356C(JNIEnv *env, jobject thiz, jstring string) {
    std::string str1="pXrZt";
    std::string str3="O]QlV";
    std::string str2="xTv\\Q";
    std::string str4="FmCjM";
    jboolean isCopy= static_cast<jboolean>(true);
    char* a= (char *) env->GetStringUTFChars(string, &isCopy);
    int len=env->GetStringUTFLength(string);
    char* b=new char[len];
    for(int i=0;i<len;i++){
        b[i]=a[i];
    }
    int s=0;
    for(int i=0;i<env->GetStringUTFLength(string);i++){
        s+=a[i];
        if((a[i]<'a'&&a[i]>'Z')||a[i]<=64){
            return static_cast<jboolean>(false);
        }
        b[i]+=i;
    }
    std::string check=str4+str2+str3+str1;
    env->ReleaseStringUTFChars(string, reinterpret_cast<const char *>(a));
    return static_cast<jboolean>(!(s != 1701 || b != check));
}
static JNINativeMethod gMethods[]={
        {"startgame","(Ljava/lang/String;)Ljava/lang/String;",((void*)M2358C)},{"checkflag","(Ljava/lang/String;)Z",((void*)M2356C)}
};
static int registerNativeMethods(JNIEnv *env, const char* className,JNINativeMethod* gMethods,int numMethods){
    jclass clazz;
    clazz=env->FindClass(className);
    if(clazz==NULL){
        return JNI_FALSE;
    }
    if((env)->RegisterNatives(clazz,gMethods,numMethods)<0){
        return JNI_FALSE;
    }
    return JNI_TRUE;
}
static int registerNatives(JNIEnv *env){
    if(!registerNativeMethods(env,JNIREG_CLASS,gMethods, sizeof(gMethods)/ sizeof(gMethods[0]))){
        return JNI_FALSE;
    }
    return JNI_TRUE;
}
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm,void* reversed){
    JNIEnv* env=NULL;
    if(((vm)->GetEnv((void**)&env,JNI_VERSION_1_4))!=JNI_OK){
        return -1;
    }
    if(!registerNatives(env)){
        return -1;
    }
    return JNI_VERSION_1_4;
}
