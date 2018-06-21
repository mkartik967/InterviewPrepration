package com.example.test4;


import android.os.Bundle;
import android.os.Environment;

import java.io.File;
import java.io.FilenameFilter;

import com.example.test4.MainActivity;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.graphics.Color;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.media.MediaPlayer.OnCompletionListener;
import android.net.Uri;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.SeekBar;
import android.widget.SeekBar.OnSeekBarChangeListener;

  public class MainActivity extends Activity implements OnCompletionListener{
	
	static AudioManager am;
	static MediaPlayer mp;
	static SeekBar sb,sb1;
	Thread t,t1;
	ListView lv;
	static View v1;
	static int n;
	Button b1,b2,b3,b4,b5;
static Uri s2;
static SharedPreferences sp;
static String s1;
static int pos=0;
static Editor e;
Intent intent,i,i1,i2,i3;
 static NotificationManager nm;
 static Notification.Builder nb;
File list[];
static int duration;
PendingIntent pi1,p1,pi2,pi3,pi4;

@Override
protected void onDestroy() {
	// TODO Auto-generated method stub
	stopService(i);
	stopService(i1);
	stopService(i2);
	stopService(i3);
	super.onDestroy();
}
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		b1=(Button) findViewById(R.id.button1);
		b2=(Button) findViewById(R.id.button2);
		b3=(Button) findViewById(R.id.button3);
		b4=(Button) findViewById(R.id.button4);
		b5=(Button) findViewById(R.id.button5);
		lv=(ListView) findViewById(R.id.listView1);
		sp=getSharedPreferences("MusicAndroid",MODE_PRIVATE);
		nm=(NotificationManager) getSystemService(NOTIFICATION_SERVICE);
		nb=new Notification.Builder(this);
		File f=new File("/storage/emulated/0/Download/");
		list=f.listFiles();
		String listshow[]=f.list();
		n=listshow.length;
		ArrayAdapter<String>adapter=new ArrayAdapter<String>(this,android.R.layout.simple_dropdown_item_1line, listshow);
		lv.setAdapter(adapter);
		lv.setOnItemClickListener(new OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
				// TODO Auto-generated method stubs
				s1=list[arg2].getAbsolutePath();
				s2=Uri.parse(s1);
				pos=arg2;
				v1=arg1;
				MainActivity.this.StopMusic(arg1);
				mp=MediaPlayer.create(MainActivity.this,s2);
				MainActivity.this.PlayMusic(arg1);
				mp.start();
			}
		});
sb=(SeekBar) findViewById(R.id.seekBar1);
sb1=(SeekBar) findViewById(R.id.seekBar2);
am=(AudioManager) getSystemService(AUDIO_SERVICE);

int max=am.getStreamMaxVolume(AudioManager.STREAM_MUSIC);
sb1.setMax(max);

sb1=(SeekBar) findViewById(R.id.seekBar2);
am=(AudioManager) getSystemService(AUDIO_SERVICE);

 max=am.getStreamMaxVolume(AudioManager.STREAM_MUSIC);
sb1.setMax(max);

t1=new Thread()                     // to ensure that the volume control bar keeps getting synced with the system vol
{

@Override
public void run() {
	// TODO Auto-generated method stub
	super.run();
	
	while(true)            // so that keeps running again and again in background
	{
		int current=am.getStreamVolume(AudioManager.STREAM_MUSIC);
		sb1.setProgress(current);
	
	}
}


};

t1.start();

sb1.setOnSeekBarChangeListener(new OnSeekBarChangeListener() {

@Override
public void onStopTrackingTouch(SeekBar seekBar) {
// TODO Auto-generated method stub

}

@Override
public void onStartTrackingTouch(SeekBar seekBar) {
// TODO Auto-generated method stub

}

@Override
public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {

am.setStreamVolume(AudioManager.STREAM_MUSIC, progress, 0);

}
});

t=new Thread()
{

@Override
public void run() {
// TODO Auto-generated method stub
super.run();

while(true)
{
	
	if(mp!=null)
	{
		sb.setProgress(mp.getCurrentPosition());
		
	}	
	
	else
	{
		
		sb.setProgress(0);
		
	}
	
}

}


};

t.start();
sb.setOnSeekBarChangeListener(new OnSeekBarChangeListener() {
	
	@Override
	public void onStopTrackingTouch(SeekBar seekBar) {
		// TODO Auto-generated method stub
		
	}
	
	@Override
	public void onStartTrackingTouch(SeekBar seekBar) {
		// TODO Auto-generated method stub
		
	}
	
	@Override
	public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
		if(fromUser)
		{
			
			if(mp!=null)
			mp.seekTo(progress);
			
		}
		
	}
});


		
		
	}
	public void generate(View v)
	{
		nb.setSmallIcon(android.R.drawable.stat_sys_headset);
		nb.setTicker("Music Player Started");       // shows before android L only !!
		nb.setContentTitle("Song Name");
		nb.setContentText(s2.toString().substring(29, s2.toString().length()));
		nb.setDefaults(Notification.DEFAULT_ALL);     // sets default light,sound,vibration
		nb.setAutoCancel(false);
		i=new Intent(this,SecondActivity.class);
		PendingIntent pi=PendingIntent.getActivity(MainActivity.this,(int)System.currentTimeMillis() , i, 0);
		nb.setContentIntent(pi);
		i1=new Intent(this,PrevService.class);
		PendingIntent pi1=PendingIntent.getService(MainActivity.this, (int)System.currentTimeMillis(), i1, 0);
		i2=new Intent(this,StopService.class);
		PendingIntent pi2=PendingIntent.getService(MainActivity.this, (int)System.currentTimeMillis(), i2, 0);
		
		i3=new Intent(this,NextService.class);
		PendingIntent pi3=PendingIntent.getService(MainActivity.this, (int)System.currentTimeMillis(), i3, 0);
		nb.addAction(android.R.drawable.ic_media_previous, "Prev", pi1);
		nb.addAction(android.R.drawable.ic_media_pause, "Play", pi2);
		nb.addAction(android.R.drawable.ic_media_next, "Next", pi3);	
		//nb.addAction(android.R.drawable.alert_light_frame, "play", pi);
		Notification n=nb.build();
		nm.notify((int)System.currentTimeMillis(),n);
	}
	public void PlayMusic(View v){
		nm.cancelAll();
		if(mp==null){
			s1=list[pos].getAbsolutePath();
			s2=Uri.parse(s1);
			mp=MediaPlayer.create(MainActivity.this,s2);
			mp.setOnCompletionListener(this);
			sb.setMax(mp.getDuration());
			mp.start();
			
		}
		else
			mp.setOnCompletionListener(this);
		sb.setMax(mp.getDuration());
			mp.start();
	
		duration=mp.getDuration();
		e=sp.edit();
		e.putString("song",s1);
		e.commit();
		this.generate(v);
		Intent i=new Intent(this,Myservice.class);
		i.putExtra("key", "play");
		startService(i);
	
		
	}
	
	public void StopMusic(View v){
		if(mp!=null){
			mp.stop();
			mp=null;
		}
	nb.setAutoCancel(true);
		}
	public void NextMusic(View v){
		if(pos!=n-1){
			pos=pos+1;
		s1=list[pos].getAbsolutePath();
		s2=Uri.parse(s1);
		this.StopMusic(v);
		mp=MediaPlayer.create(MainActivity.this,s2);
		this.PlayMusic(v);
		}
		else{
			s1=list[0].getAbsolutePath();
			s2=Uri.parse(s1);
			pos=0;
			MainActivity.this.StopMusic(v);
			mp=MediaPlayer.create(MainActivity.this,s2);
			MainActivity.this.PlayMusic(v);
		}
	}
	public void PrevMusic(View v){
		if(pos!=0)
			pos=pos-1;
			else
				pos=n-1;
				s1=list[pos].getAbsolutePath();
				s2=Uri.parse(s1);
				MainActivity.this.StopMusic(v);
				mp=MediaPlayer.create(MainActivity.this,s2);
				MainActivity.this.PlayMusic(v);
			
	}
	public void PauseMusic(View v){
		if(mp!=null)
			mp.pause();
		Intent i=new Intent(this,Myservice.class);
		i.putExtra("key", "pause");
		startService(i);
	}
	public boolean onOptionsItemSelected(MenuItem item) {
		// TODO Auto-generated method stub
		if(item.getTitle().toString().equals("Red"))
		{
			lv.setBackgroundColor(Color.RED);
		}
		else if(item.getTitle().toString().equals("Blue"))
		{
			lv.setBackgroundColor(Color.BLUE);
		
		}
		else if(item.getTitle().toString().equals("Green"))
		{
			lv.setBackgroundColor(Color.GREEN);
		}
			
		return super.onOptionsItemSelected(item);
	}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public void onCompletion(MediaPlayer arg0) {
		// TODO Auto-generated method stub
		this.NextMusic(null);
		
	}
	

}
