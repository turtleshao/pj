package com.example.crackme;

import androidx.appcompat.app.AppCompatActivity;

import android.nfc.Tag;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import static com.example.crackme.R.layout.activity_main;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(activity_main);
        final EditText editText = findViewById(R.id.editText);
        Log.d(TAG,"啥u算法");
        findViewById(R.id.button).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                /*
                运算一下s得到一串字符串，用来在后门中和s作比较，保证两个字符串相互关联
                 */
                final String s = editText.getText().toString();
                Toast toast = Toast.makeText(MainActivity.this, s, Toast.LENGTH_LONG);
                toast.show();
            }
        });
    }
}
