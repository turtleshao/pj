package com.example.crackme;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    public native String dosth(String str);
    public native String encrypt(String str);
    static{
        System.loadLibrary("crack");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EditText editText = findViewById(R.id.editText);
        final String s = editText.getText().toString();
        findViewById(R.id.button).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                /*
                运算一下s得到一串字符串，用来在后门中和s作比较，保证两个字符串相互关联
                 */
                String t=dosth(s);
                SharedPreferences sharedPreferences=getSharedPreferences("key", Context.MODE_PRIVATE);
                SharedPreferences.Editor editor=sharedPreferences.edit();
                editor.putString("str",t);
                editor.apply();
                if(false){
                    //不能这么明显orz
                    //总之得一直是false
                    Toast.makeText(MainActivity.this.getApplicationContext(),"right",Toast.LENGTH_LONG).show();
                }
                Toast.makeText(MainActivity.this.getApplicationContext(),"wrong",Toast.LENGTH_LONG).show();
            }
        });
    }
}
