#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	long long int m,n;
	cin>>t;
	while(t--){
		cin>>m>>n;
		if(n==1 || m==1 )
		if(n==2 || m==2)
			cout<<"Yes"<<endl;
			else
			cout<<"No"<<endl;
		else 
		{if(m%2==0)
		cout<<"Yes"<<endl;
		else if(m%2!=0 && n%2==0)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	}
}
