#include<bits/stdc++.h>
#define ll long long
#define mod 1000007
#define max 1000009
#define pb push_back
using namespace std;
typedef pair<int,int>p;
map<int,int>mp;
vector<int>v;
int main(){
	ll int t,n,i,j,k,m;
	std::ios::sync_with_stdio(false);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
	if(n==1&&m==1)
	cout<<0<<endl;
	else if(n==1&&m!=1)
	cout<<(m-1)<<endl;
	else if(m==1&&n!=1)
	cout<<(n-1)<<endl;
	else{
		cout<<((n-1)+(m-1)+2*(n-1)*(m-1))<<endl;
	}
	}
} 
