package com.example.crackme;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class mActivity extends Activity {
    public void onCreate(Bundle bundle) {
        super.onCreate(bundle);
        String s=getIntent().getStringExtra("msg");
        /*
        填入判断函数，结合MainActivity中得到的另一个s，判断Intent中得到的信息msg输入是否符合条件，如果符合则继续，否则退出
        此处打算用native函数判断来迷惑一下
         */
        setContentView(R.layout.m_main);
        EditText editText= findViewById(R.id.editText2);
        String s1=editText.getText().toString();
        findViewById(R.id.button2).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                /*
                判断flag是否正确
                 */
            }
        });
    }
}
