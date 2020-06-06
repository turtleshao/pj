package com.example.crackme;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class mActivity extends Activity {
    public native boolean check(String str1,String str2);
    public native boolean a(String str1,String str2);
    static {
        System.loadLibrary("native-lib2");
    }
    public void onCreate(Bundle bundle) {
        super.onCreate(bundle);
        boolean b=false;
        try {
            throw new Exception(BuildConfig.FLAVOR);
        } catch (Exception localException) {
            for (StackTraceElement className : localException.getStackTrace()) {
                if (className.getClassName().equals("de.robv.android.xposed.XposedBridge")){
                    b=true;
                    break;
                }
            }
        }
        if(b){
            setContentView(R.layout.w_main);
        } else{
            final String s=getIntent().getStringExtra(texts.a("nth"));
            SharedPreferences sharedPreferences=getSharedPreferences(texts.a("lfz"), Context.MODE_PRIVATE);
            final String t=sharedPreferences.getString("str",texts.a("efgbvmu"));
            if(check(s,t)){
                setContentView(R.layout.w_main);
                final TextView helloTextView = findViewById(R.id.textView);
                helloTextView.setText(R.string.flag_not_here);
            }
            setContentView(R.layout.m_main);
            final EditText editText= findViewById(R.id.editText2);
            findViewById(R.id.button2).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    final String s1=editText.getText().toString();
                    if(a(s1,signit.getSignature(mActivity.this))){
                        Toast.makeText(mActivity.this.getApplicationContext(),texts.a("sjhiu/"),Toast.LENGTH_LONG).show();
                    } else{
                        Toast.makeText(mActivity.this.getApplicationContext(),texts.a("xspoh/"),Toast.LENGTH_LONG).show();
                    }
                }
            });
        }
    }
}
