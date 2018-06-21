#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int i,j,k,n,l,p;
		cin>>n;
	long long v[n][n];
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	cin>>v[i][j];
	for(i=0;i<n;i++)
	sort(v[i],v[i]+n);
long long sum=0;
	bool flag=1;
	long long maximum=INT_MAX;
	for(i=n-1;i>=0;i--)
	{
		long long temp=INT_MIN;
		
	for(j=n-1;j>=0;j--)
	{
		if(v[i][j]<maximum)
		break;
	
	}
	if(j<0)
	{
		flag=0;
		break;
	}
	else
	{
	sum+=v[i][j];
	maximum=v[i][j];	
}
	}
	if(!flag)
	cout<<-1<<endl;
	else
	cout<<sum<<endl;
	
	}
}
