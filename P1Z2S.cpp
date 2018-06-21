#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k=0,m=0;
	cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];	
		int l=n;
		for(int j=0;j<n;j++){
	if(a[j]==1)
	k++;
	else
	m=m+a[j]-2;
}
if(k>=m)
cout<<l<<endl;
else{
	if((k-m)%2==0)
	cout<<(l+(m-k)/2)<<endl;
	else
	cout<<(l+(m-k+1)/2)<<endl;
}	
}
