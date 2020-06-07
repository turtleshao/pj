#include <jni.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/ptrace.h>

#define JNIREG_CLASS "com/example/crackme/mActivity"
extern "C" JNIEXPORT jboolean JNICALL M2354C(JNIEnv *env, jobject thiz, jstring str1,
                                             jstring str2) {
    jboolean isCopy= static_cast<jboolean>(false);
    int len=env->GetStringUTFLength(str2),lem=env->GetStringUTFLength(str1);
    if(lem!=len){
        return static_cast<jboolean>(false);
    }
    char* s1= (char *) env->GetStringUTFChars(str1, &isCopy);
    char* s2= (char *) env->GetStringUTFChars(str2, &isCopy);
    for(int i=0;i<len;i++){
        if((i%2)==0 && s1[i]==s2[i])
            continue;
        if((i%2)==1 && s1[i]==(s2[i]+1))
            continue;
        env->ReleaseStringUTFChars(str1, reinterpret_cast<const char *>(s1));
        env->ReleaseStringUTFChars(str2, reinterpret_cast<const char *>(s2));
        return static_cast<jboolean>(false);
    }
    env->ReleaseStringUTFChars(str1, reinterpret_cast<const char *>(s1));
    env->ReleaseStringUTFChars(str2, reinterpret_cast<const char *>(s2));
    return static_cast<jboolean>(true);
}
extern "C" JNIEXPORT jboolean JNICALL M2352C(JNIEnv *env, jobject thiz, jstring jstring1,jstring jstring2) {
    jboolean isCopy= static_cast<jboolean>(false);
    char* a= (char *) env->GetStringUTFChars(jstring1, &isCopy);
    char* b= (char *) env->GetStringUTFChars(jstring2, &isCopy);
    if(env->GetStringUTFLength(jstring1)!=16||env->GetStringUTFLength(jstring2)!=32){
        return static_cast<jboolean>(false);
    }
    unsigned char c[32];
    unsigned char d[16];
    unsigned char r[48];
    unsigned char m[48]={(unsigned char)183,(unsigned char)223,(unsigned char)155,(unsigned char)116,(unsigned char)200,(unsigned char)104,\
                        (unsigned char)90,(unsigned char)116,(unsigned char)119,(unsigned char)238,(unsigned char)138,(unsigned char)139,\
                        (unsigned char)6,(unsigned char)194,(unsigned char)191,(unsigned char)53,(unsigned char)104,(unsigned char)32,\
                        (unsigned char)57,(unsigned char)68,(unsigned char)23,(unsigned char)43,(unsigned char)106,(unsigned char)81,\
                        (unsigned char)104,(unsigned char)196,(unsigned char)117,(unsigned char)138,(unsigned char)140,(unsigned char)119,\
                        (unsigned char)17,(unsigned char)78,(unsigned char)240,(unsigned char)69,(unsigned char)135,(unsigned char)65,\
                        (unsigned char)6,(unsigned char)255,(unsigned char)233,(unsigned char)147,(unsigned char)6,(unsigned char)169,\
                        (unsigned char)57,(unsigned char)26,(unsigned char)248,(unsigned char)125,(unsigned char)200,(unsigned char)196};
    for(int i=0;i<32;i++){
        if(b[i]>='0'&&b[i]<='9')
            c[i]= static_cast<unsigned char>(b[i] - '0');
        if(b[i]>='a'&&b[i]<='f')
            c[i]= static_cast<unsigned char>(b[i] - 'a'+10);
    }
    for(int i=0;i<16;i++){
        d[i]= static_cast<unsigned char>(c[i * 2] * 16 + c[i * 2 + 1]);
    }
    for(int i=0;i<16;i++){
        c[i*2]= static_cast<unsigned char>(a[i]);
        srand(d[i]);
        c[i*2+1]= static_cast<unsigned char>(rand() % 256);
    }
    for(int i=0;i<16;i++){
        r[i*3]=c[i*2]-c[i*2+1]+d[i];
        r[i*3+1]=(c[i*2]>>1)+(c[i*2+1]>>1)+d[i];
        r[i*3+2]= ((c[i * 2 + 1] & (unsigned char)0x81) | ((c[i * 2] &(unsigned char) 0x81) >> 4))+d[i];
    }
    for(int i=0;i<48;i++){
        if(r[i]==m[i]){
            continue;
        }
        env->ReleaseStringUTFChars(jstring1, reinterpret_cast<const char *>(a));
        env->ReleaseStringUTFChars(jstring2, reinterpret_cast<const char *>(b));
        return static_cast<jboolean>(false);
    }
    env->ReleaseStringUTFChars(jstring1, reinterpret_cast<const char *>(a));
    env->ReleaseStringUTFChars(jstring2, reinterpret_cast<const char *>(b));
    return static_cast<jboolean>(true);
}
static JNINativeMethod gMethods[]={
        {"check","(Ljava/lang/String;Ljava/lang/String;)Z",(void*)M2354C},{"a","(Ljava/lang/String;Ljava/lang/String;)Z",((void*)M2352C)}
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
    if(ptrace(PTRACE_TRACEME,0,0,0)==-1){
        exit(0);
    }
    JNIEnv* env=NULL;
    if(((vm)->GetEnv((void**)&env,JNI_VERSION_1_4))!=JNI_OK){
        return -1;
    }
    if(!registerNatives(env)){
        return -1;
    }
    return JNI_VERSION_1_4;
}
