package com.example.crackme;

class texts {
    static String a(String string){
        char[] s=string.toCharArray();
        for(int i=0;i<s.length;i++){
            s[i]--;
        }
        return String.valueOf(s);
    }
}
