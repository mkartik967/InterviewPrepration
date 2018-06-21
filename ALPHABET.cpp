#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int n;
	string wi;
	cin>>s;
	int a[26];
	memset(a,0,sizeof(a));
	int l=s.length();
	for(int i=0;i<l;i++)
	a[s[i]-97]++;
	cin>>n;
	while(n--){
			int flag=1;
		cin>>wi;
		int l2=wi.length();
		for(int j=0;j<l2;j++)
		if(a[wi[j]-97]==0)
		{
			flag=0;
			break;
		}
		(flag)?cout<<"Yes"<<endl:cout<<"No"<<endl;
	}
	
} 
