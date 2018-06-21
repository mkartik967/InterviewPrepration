#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int t,i,j,n,m,x,k;
	cin>>t;
	while(t--)
	{
	cin>>n>>m>>x>>k;
	string s;
	cin>>s;
	int even=0,odd=0;
	for(i=0;i<s.length();i++)
	if(s[i]=='E')
	even++;
	else
	odd++;
	int count=0;
	for(i=1;i<=m;i++)
	{
		if(i%2)
		{
		count+=min(odd,x);
		odd-=min(odd,x);
	}
		else 
		{
		count+=min(even,x);
		even-=min(even,x);
	}
	}
	if(count>=n)
	cout<<"yes"<<endl;
	else
	cout<<"no"<<endl;
	
	}
	
}
 
