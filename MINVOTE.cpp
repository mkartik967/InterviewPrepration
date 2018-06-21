#include<bits/stdc++.h>
using namespace std;
 
int main()
{
long long	int i,j,n,t,q,l,r;
 
long long h,k;
	cin>>n>>q;
long long a[n];
for(i=0;i<n;i++)
cin>>a[i];
long long dp[n+1][32];
for(i=0;i<=n;i++)
for(j=0;j<32;j++)
dp[i][j]=0;
for(i=1;i<=n;i++)
{
 
for(j=0;j<31;j++)
{
	dp[i][j]=dp[i-1][j];
if((a[i-1]&(1<<j)))
dp[i][j]++;	
}
}
 
while(q--)
{
	cin>>l>>r;
	
	long long ans=0;
	for(i=0;i<31;i++)
	{
	int	count=dp[r][i]-dp[l-1][i];
if(count<((r-l+1)-count))
ans=ans+pow(2,i);
}
cout<<ans<<endl;	
 
	
	
}
} 
