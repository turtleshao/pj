package com.example.crackme;

import androidx.appcompat.app.AppCompatActivity;
import static com.example.crackme.R.layout.activity_main;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    public native String startgame(String str);
    public native boolean checkflag(String str);
    static{
        System.loadLibrary("native-lib");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(activity_main);
        final EditText editText = findViewById(R.id.editText);
        findViewById(R.id.button).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                final String s = editText.getText().toString();
                String t=startgame(s);
                SharedPreferences sharedPreferences=getSharedPreferences(texts.a("lfz"), Context.MODE_PRIVATE);
                SharedPreferences.Editor editor=sharedPreferences.edit();
                editor.putString(texts.a("tus"),t);
                editor.apply();
                if(checkflag(t)){
                    Toast.makeText(MainActivity.this.getApplicationContext(),texts.a("Sjhiu!botxfs"),Toast.LENGTH_LONG).show();
                }
                Toast.makeText(MainActivity.this.getApplicationContext(),texts.a("xspoh!gpsfwfs"),Toast.LENGTH_LONG).show();
            }
        });
    }
}
