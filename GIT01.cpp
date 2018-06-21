#include<bits/stdc++.h>
using namespace std;
#define INF 1000000
int main()
{
int i,j,k,t,n,m;
cin>>t;
while(t--)
{
cin>>n>>m;
char a[n][m];
for(i=0;i<n;i++)
for(j=0;j<m;j++)
cin>>a[i][j];
char a1[n][m];
char a2[n][m];
bool flag=0;
for(i=0;i<n;i++)
{
flag=!flag;
for(j=0;j<m;j++)
{
	if(j==0)
	{
		if(flag)
		a1[i][j]='R';
		else
		a1[i][j]='G';
	}
	else
	{
	if(a1[i][j-1]=='G')
		a1[i][j]='R';
		else
		a1[i][j]='G';
	}
}
}
 flag=1;
for(i=0;i<n;i++)
{
flag=!flag;
for(j=0;j<m;j++)
{
	if(j==0)
	{
		if(flag)
		a2[i][j]='R';
		else
		a2[i][j]='G';
	}
	else
	{
	if(a2[i][j-1]=='G')
		a2[i][j]='R';
		else
		a2[i][j]='G';
	}
}
}
int ans=INT_MAX;
int cost=0;
for(i=0;i<n;i++)
for(j=0;j<m;j++)
{
	if(a[i][j]!=a1[i][j])
	{
		if(a1[i][j]=='R')
		cost+=3;
		else
		cost+=5;
	}
}
ans=min(cost,ans);
cost=0;
for(i=0;i<n;i++)
for(j=0;j<m;j++)
{
	if(a[i][j]!=a2[i][j])
	{
		if(a2[i][j]=='R')
		cost+=3;
		else
		cost+=5;
	}
}
ans=min(cost,ans);
cout<<ans<<endl;
}
}  
