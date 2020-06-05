package com.example.crackme;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.SharedPreferences;
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
        String x = "flag";
        findViewById(R.id.button).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                final String s = editText.getText().toString();
                String t = s;
                SharedPreferences sharedPreferences=getSharedPreferences("key", Context.MODE_PRIVATE);
                SharedPreferences.Editor editor=sharedPreferences.edit();
                editor.putString("str",t);
                editor.apply();
//                Toast toast = Toast.makeText(MainActivity.this, s, Toast.LENGTH_LONG);
//                toast.show();
                if (checkflag(s)){
                    Toast.makeText(MainActivity.this.getApplicationContext(),"Right answer",Toast.LENGTH_LONG).show();
                }
                Toast.makeText(MainActivity.this.getApplicationContext(),"wrong forever",Toast.LENGTH_LONG).show();
            }
        });
    }
    private boolean checkflag(String t) {
        String a1 = "pXrZt";//4
        String a3 = "O]QlV";//3
        String a2 = "xTv\\Q";//2
        String a4 = "FmCjM";//1

        char[] a = t.toCharArray();
        int sum = 0;
        for(int i = 0; i < t.length(); i++) {
            sum += a[i];
            if((a[i] < 'a' && a[i] > 'Z')||a[i] <= 64)
                return false;
            a[i] += i;
            System.out.println(a[i]);
        }
        String soeasy = a4+a2+a3+a1;
        String s = String.valueOf(a);
        if(sum != 1701 || !s.equals(soeasy)) return false;
        return true;
    }
}
