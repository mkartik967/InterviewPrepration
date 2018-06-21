#include<bits/stdc++.h>
#define ll long long
#define mod 1000007
#define pb push_back
using namespace std;
typedef pair<int,int>p;
int main(){
	int t,n,i,q;
	cin>>n>>q;
	int a[n];
	for( i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	while(q--){
		cin>>t;
		if(t>=a[0]&&t<=a[n-1])
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
} 
