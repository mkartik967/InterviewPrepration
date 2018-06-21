package com.example.test4;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;

public class StopService extends Service{
	Intent i1,i2,i;
@Override
public int onStartCommand(Intent intent, int flags, int startId) {
	i1=new Intent(getApplicationContext(),PrevService.class);
	stopService(i1);
	i2=new Intent(getApplicationContext(),NextService.class);
	stopService(i2);
	if(MainActivity.mp!=null){
		MainActivity.mp.stop();
		MainActivity.mp=null;
	}

	return super.onStartCommand(intent, flags, startId);
}
@Override
public void onDestroy() {
	MainActivity.nb.setAutoCancel(true);
	if(MainActivity.mp!=null){
		MainActivity.mp.stop();
		MainActivity.mp=null;
	}
	super.onDestroy();
}

	@Override
	public IBinder onBind(Intent intent) {
		// TODO Auto-generated method stub
		return null;
	}

}
