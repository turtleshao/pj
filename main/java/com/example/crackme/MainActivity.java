package com.example.crackme;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EditText editText = findViewById(R.id.editText);
        String s = editText.getText().toString();
        findViewById(R.id.button).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                /*
                运算一下s得到一串字符串，用来在后门中和s作比较，保证两个字符串相互关联
                 */
            }
        });
    }
}
