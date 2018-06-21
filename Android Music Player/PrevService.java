package com.example.test4;

import android.app.Service;
import android.content.Intent;
import android.media.MediaPlayer;
import android.net.Uri;
import android.os.IBinder;

public class PrevService extends Service{
	Intent i,i1,i2;
@Override
public int onStartCommand(Intent intent, int flags, int startId) {
	i1=new Intent(getApplicationContext(),NextService.class);
	stopService(i1);
	i2=new Intent(getApplicationContext(),StopService.class);
	stopService(i2);
	if(MainActivity.pos!=0)
	MainActivity.pos=MainActivity.pos-1;
	else
		MainActivity.pos=MainActivity.n-1;	
	if(MainActivity.mp!=null)
	{
		MainActivity.mp.stop();
		MainActivity.mp=null;
	}
	MainActivity.mp=MediaPlayer.create(getApplicationContext(), MainActivity.s2);
	i=new Intent(getApplicationContext(), Myservice.class);
	startService(i);
	return super.onStartCommand(intent, flags, startId);
}
@Override
public void onDestroy() {
	if(MainActivity.mp!=null){
		MainActivity.mp.stop();
		MainActivity.mp=null;
	}
	super.onDestroy();
}

	@Override
	public IBinder onBind(Intent arg0) {
		// TODO Auto-generated method stub
		return null;
	}

}
