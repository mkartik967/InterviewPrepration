#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define max 1000009
#define pb push_back
using namespace std;
typedef pair<int,int>p;
map<int,int>mp;
vector<int>v;
int main(){
	ll int t,n,i,j,k,m,p;
	std::ios::sync_with_stdio(false);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
	p=(n-1)+n*(m-1);
	if(p%2==0)
		cout<<"No"<<endl;
		else
		cout<<"Yes"<<endl;
	}
} 
