#include<bits/stdc++.h>
using namespace std;
int f(int s[],int n,int k[]){
	for(int i=0;i<n;i++)
	{
	if(s[i]==k[2])
	return i;
	}
}
 
int main(){
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
	cin>>n;
	int s[3]={0};
	char a[n];
	for(int j=0;j<n;j++){
		cin>>a[j];
	}
	for(int k=0;k<n;k++){
 
	if(a[k]=='R')
	s[0]++;
	else if (a[k]=='B')
	s[1]++;
	else
	s[2]++;
}
	sort(s,s+3);
	cout<<s[0]+s[1]<<endl;
}
}
