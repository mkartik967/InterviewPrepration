#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i,j,k;
   cin>>t;
   map<string,int>mp;
   mp["mon"]=0;
    mp["tues"]=1;
     mp["wed"]=2;
      mp["thurs"]=3;
      mp["fri"]=4;
    mp["sat"]=5;
     mp["sun"]=6;
   while(t--)
   {
   	int d;
   	string s;
   	cin>>d>>s;
   	int days[7];
   	k=d/7;
   	for(i=0;i<7;i++)
   	days[i]=0;
   	for(i=0;i<7;i++)
days[i]=k;
for(i=0;i<d%7;i++)
days[(mp[s]+i)%7]++;
for(i=0;i<7;i++)
cout<<days[i]<<" ";
cout<<endl;
   }
} 
