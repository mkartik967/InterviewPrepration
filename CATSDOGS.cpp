#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll i,j,k,t,n,c,d,l;
	cin>>t;
	while(t--){
		cin>>c>>d>>l;
		j=4*c+4*d;
		if(c>2*d)
		k=d+(c-2*d);
		else
		k=d;
		if(l%4==0){
		if(l<=j&&l>=4*k)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
	else
	cout<<"no"<<endl;
}
}
