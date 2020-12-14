package com.cbbinder;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.cb.IBinderCommService;
import com.cb.IBinderCommCallback;
import com.cb.PackageInfo;

import java.io.BufferedReader;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.text.AttributedCharacterIterator;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "BinderTest";
    private IBinderCommService mService = null;


    private TextView txt = null ;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button btn = (Button) findViewById(R.id.button);
        txt = (TextView) findViewById(R.id.txtLabel);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (mService != null) {
                    try {
                        PackageInfo packageInfo[] = mService.getPackageInfo();
                        if (packageInfo != null && packageInfo.length > 0 ) {
                            String msg = String.format("ID:%d Name: %s", packageInfo[0].mID, packageInfo[0].mName );
                            txt.setText(msg);
                        }
                    } catch (RemoteException e) {
                        e.printStackTrace();
                    }
                }
            }
        });

        mService = getBinderCommService();
        try {
            mService.registerCallback(callback);
        } catch (RemoteException e) {
            e.printStackTrace();
        }

    }

    private IBinderCommService getBinderCommService() {
        Method method;
        try {
            method = Class.forName("android.os.ServiceManager").getMethod("getService", String.class);
            IBinder binder = (IBinder) method.invoke(null, "nativecbbinder");
            if (binder != null) {
                mService = IBinderCommService.Stub.asInterface(binder);
                Log.d(TAG, "nativecbbinder Service bounded.");
            }
        } catch (NoSuchMethodException | ClassNotFoundException | IllegalAccessException | InvocationTargetException e) {
            e.printStackTrace();
        }
        return mService;
    }

    private IBinderCommCallback callback = new IBinderCommCallback.Stub() {
        @Override
        public void onChangeEvent(int event) throws RemoteException {
            String msg = String.format("Event: %d", event);
            txt.setText(msg);
        }
    } ;
}