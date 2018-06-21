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
	 int t,n,i,j,k,r,c,sum;
	std::ios::sync_with_stdio(false);cin.tie(0);
	cin>>t;
	while(t--){
		sum=0;
		cin>>r>>c;
		char a[r][c];
		for( i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		cin>>a[i][j];
	}
	for(j=0;j<c;j++){
		k=0;
		for(i=0;i<r;i++){
			if(a[i][j]=='1')
		k++;
		}
	
		sum+=(k*(k-1))/2;	
	}
	cout<<sum<<endl;
	}
} 
