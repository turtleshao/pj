package com.example.crackme;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.text.Editable;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class mActivity extends Activity {
    private static final String TAG = "mActivity";

    public void onCreate(Bundle bundle) {
        super.onCreate(bundle);
        String s = getIntent().getStringExtra("msg");
        SharedPreferences sharedPreferences = getSharedPreferences("key", Context.MODE_PRIVATE);
        String t = sharedPreferences.getString("str","");
        if(check(s,t)){
            setContentView(R.layout.w_main);
            final TextView helloTextView = findViewById(R.id.textView);
            helloTextView.setText(R.string.flag_not_here);
        }
        else {
            setContentView(R.layout.m_main);
            final EditText editText = findViewById(R.id.editText2);
            findViewById(R.id.button2).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    String s1 = editText.getText().toString();
                    Toast toast = Toast.makeText(mActivity.this, s1, Toast.LENGTH_LONG);
                    toast.show();
                    /**/
                }
            });
        }
    }
    private boolean check(String s, String t) {
        int i = 0, len = t.length();
        Log.d(TAG,len+"here");
        char[] c = t.toCharArray();
        while (i < len - 1){
            if(i % 2 == 1){
                c[i] = '0';
            }
            i++;
        }
        String h = String.valueOf(c);
        if (s.equals(h)) return false;
        else return true;
    }

}
