#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k,n,t,s;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>s;
		if(k>n)
		{
			cout<<-1<<endl;
			continue;
		}
		bool flag=0;
		for(i=1;i<=s;i++)
		{
			if((n*(i-i/7)>=s*k))
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		cout<<-1<<endl;
		else
		cout<<i-i/7<<endl;
	
	}
} 
