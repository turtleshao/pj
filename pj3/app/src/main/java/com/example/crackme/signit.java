package com.example.crackme;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.Signature;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

class signit {
    private static String m(byte[] bytes){
        MessageDigest messageDigest=null;
        StringBuffer stringBuffer=new StringBuffer();
        try{
            messageDigest=MessageDigest.getInstance("MD5");
            messageDigest.reset();
            messageDigest.update(bytes);
            byte[] bytes1=messageDigest.digest();
            for (byte b : bytes1) {
                if (Integer.toHexString(0xFF & b).length() == 1) {
                    stringBuffer.append("0").append(Integer.toHexString(0xFF & b));
                } else {
                    stringBuffer.append(Integer.toHexString(0xFF & b));
                }
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return stringBuffer.toString();
    }
    private static String checker(Context context, String str){
        byte[] a=null;
        try{
            PackageInfo packageInfo=context.getPackageManager().getPackageInfo(str, PackageManager.GET_SIGNATURES);
            Signature[] signatures=packageInfo.signatures;
            for (Signature signature : signatures) {
                a = signature.toByteArray();
                if (a != null)
                    break;
            }
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        return m(a);
    }

    public static String getSignature(Context context) {
        return checker(context, context.getApplicationInfo().packageName);
    }
}
