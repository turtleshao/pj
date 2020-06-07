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
    char* s1= (char *) env->GetStringChars(str1, &isCopy);
    char* s2= (char *) env->GetStringChars(str2, &isCopy);
    int len=env->GetStringLength(str2);
    for(int i=0;i<len;i++){
        if((i%2)==0 && s1[i]==s2[i])
            continue;
        if((i%2)==1 && s1[1]=='0')
            continue;
        env->ReleaseStringChars(str1, reinterpret_cast<const jchar *>(s1));
        env->ReleaseStringChars(str2, reinterpret_cast<const jchar *>(s2));
        return static_cast<jboolean>(false);
    }
    env->ReleaseStringChars(str1, reinterpret_cast<const jchar *>(s1));
    env->ReleaseStringChars(str2, reinterpret_cast<const jchar *>(s2));
    return static_cast<jboolean>(true);
}
extern "C" JNIEXPORT jboolean JNICALL M2352C(JNIEnv *env, jobject thiz, jstring jstring1,jstring jstring2) {
    jboolean isCopy= static_cast<jboolean>(false);
    char* a= (char *) env->GetStringChars(jstring1, &isCopy);
    char* b= (char *) env->GetStringChars(jstring2, &isCopy);
    if(env->GetStringLength(jstring1)!=32||env->GetStringLength(jstring2)!=16){
        return static_cast<jboolean>(false);
    }
    unsigned char c[32];
    unsigned char d[16];
    unsigned char r[48];
    unsigned char m[48]={(unsigned char)0x171,(unsigned char)0x126,(unsigned char)0x129,(unsigned char)0x38,(unsigned char)0x85,\
                        (unsigned char)0x0,(unsigned char)0x179,(unsigned char)0x87,(unsigned char)0x0,(unsigned char)0x231,(unsigned char)0x127,\
                        (unsigned char)0x128,(unsigned char)0x143,(unsigned char)0x161,(unsigned char)0x128,(unsigned char)0x172,(unsigned char)0x124,\
                        (unsigned char)0x129,(unsigned char)0x230,(unsigned char)0x77,(unsigned char)0x0,(unsigned char)0x101,(unsigned char)0x147,\
                        (unsigned char)0x129,(unsigned char)0x252,(unsigned char)0x74,(unsigned char)0x1,(unsigned char)0x71,(unsigned char)0x61,\
                        (unsigned char)0x0,(unsigned char)0x99,(unsigned char)0x63,(unsigned char)0x0,(unsigned char)0x123,(unsigned char)0x138,\
                        (unsigned char)0x129,(unsigned char)0x244,(unsigned char)0x106,(unsigned char)0x1,(unsigned char)0x249,(unsigned char)0x85,\
                        (unsigned char)0x1,(unsigned char)0x136,(unsigned char)0x128,(unsigned char)0x129,(unsigned char)0x68,(unsigned char)0x126,\
                        (unsigned char)0x129};
    for(int i=0;i<32;i++){
        if(a[i]>='0'&&a[i]<='9')
            c[i]= static_cast<unsigned char>(a[i] - '0');
        if(a[i]>='A'&&a[i]<='F')
            c[i]= static_cast<unsigned char>(a[i] - 'A'+10);
    }
    for(int i=0;i<16;i++){
        d[i]= static_cast<unsigned char>(c[i * 2] * 10 + c[i * 2 + 1]);
    }
    for(int i=0;i<16;i++){
        c[i*2]= static_cast<unsigned char>(b[i]);
        srand(d[i]);
        c[i*2+1]= static_cast<unsigned char>(rand() % 256);
    }
    for(int i=0;i<16;i++){
        r[i*3]=c[i*2]-c[i*2+1];
        r[i*3+1]=(c[i*2]>>1)+(c[i*2+1]>>1);
        r[i*3+2]= (c[i * 2] & (unsigned char)0x81) | ((c[i * 2 + 1] &(unsigned char) 0x81) >> 4);
    }
    for(int i=0;i<48;i++){
        if(r[i]==m[i]){
            continue;
        }
        env->ReleaseStringChars(jstring1, reinterpret_cast<const jchar *>(a));
        env->ReleaseStringChars(jstring2, reinterpret_cast<const jchar *>(b));
        return static_cast<jboolean>(false);
    }
    env->ReleaseStringChars(jstring1, reinterpret_cast<const jchar *>(a));
    env->ReleaseStringChars(jstring2, reinterpret_cast<const jchar *>(b));
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
