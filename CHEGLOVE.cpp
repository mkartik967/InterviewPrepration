#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k,n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		int g[n];
		for(i=0;i<n;i++)
		cin>>g[i];
		bool front=1,back=1;
		for(i=0;i<n;i++)
		if(a[i]>g[i])
		{
			front=0;
			break;
		}
		reverse(g,g+n);
		for(i=0;i<n;i++)
		if(a[i]>g[i])
		{
			back=0;
			break;
		}
		if(front&&back)
		cout<<"both"<<endl;
		else if(front)
		cout<<"front"<<endl;
		else if(back)
		cout<<"back"<<endl;
		else
		cout<<"none"<<endl;
		
		
	}
} 
