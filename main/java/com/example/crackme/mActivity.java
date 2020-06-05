package com.example.crackme;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.text.Editable;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class mActivity extends Activity {
    public native boolean sthIsHappening(String str1,String str2);
    public native boolean a(String string);
    public void onCreate(Bundle bundle) {
        super.onCreate(bundle);
        String s=getIntent().getStringExtra("msg");
        SharedPreferences sharedPreferences=getSharedPreferences("key", Context.MODE_PRIVATE);
        String t=sharedPreferences.getString("str","default");
        if(sthIsHappening(s,t)){
            return;
        }
        setContentView(R.layout.m_main);
        EditText editText= findViewById(R.id.editText2);
        final String s1=editText.getText().toString();
        findViewById(R.id.button2).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                /*
                判断flag是否正确
                 */
                a(s1);
            }
        });
    }
}
