#include<bits/stdc++.h>
using namespace std;
long long  int a[100000000];
int main(){
	long long int n,i;
	cin>>n;
	for( i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	long long count=1;
	long long min=1;
	for(i=0;i<n;i++){
		min=a[i]*(n-i);
		if(min>count)
		count=min;
	}
	cout<<count<<endl;
} 
