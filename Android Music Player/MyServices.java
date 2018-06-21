package com.example.test4;

import java.io.File;
import android.annotation.SuppressLint;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.Service;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.media.MediaPlayer;
import android.os.IBinder;
import android.view.View;


public class Myservice extends Service{
//	NotificationManager nm;
//	Notification.Builder nb;
	SharedPreferences sp;
	MediaPlayer mp;
	String s2,s3;
	int id;
	Editor e;
	static int n;
	static File list[];
	Intent i1,i2,i3;
	@Override
	public int onStartCommand(Intent intent, int flags, int startId) {
		
		final File f=new File("/storage/emulated/0/Download/");
		list=f.listFiles();
		final String listshow[]=f.list();
		n=listshow.length;
		s3=intent.getStringExtra("key");
		MainActivity.nm=(NotificationManager) getSystemService(NOTIFICATION_SERVICE);	
		if(s3=="play"){
			this.PlayMusic(MainActivity.v1);
		}
		if(s3=="pause"){
			this.PauseMusic(MainActivity.v1);
		}
		if(s3=="stop"){
			this.StopMusic(MainActivity.v1);
		}
		
		return super.onStartCommand(intent, flags, startId);
	}
	public void StopMusic(View v){
		if(mp!=null){
			mp.stop();
			mp=null;
		}
			
		}
	public void PauseMusic(View v){
		if(mp!=null)
			mp.pause();
	}
	public void PlayMusic(View v){
		if(mp==null){
			mp=MediaPlayer.create(this,MainActivity.s2);
			//MainActivity.mp.setOnCompletionListener(MainActivity.this);
			MainActivity.sb.setMax(mp.getDuration());
			mp.start();
			//mp.start();
		}
		else
		{
			
			MainActivity.sb.setMax(mp.getDuration());
			mp.start();
			//mp.start();
		}
		
	}


	@Override
	public IBinder onBind(Intent arg0) {
		// TODO Auto-generated method stub
		return null;
	}

}
