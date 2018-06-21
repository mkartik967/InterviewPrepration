#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k,n,t;
	cin>>t;
	while(t--)
	{
	cin>>n;
	set<int>st;
	long long int a[n];
		for(i=0;i<n;i++)
		{
		cin>>a[i];
		st.insert(a[i]);
	}
	k=n-st.size();
	sort(a,a+n);
	int ans=0;
cout<<k<<endl;	
		
	}
} 
