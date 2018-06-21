#include<bits/stdc++.h>
using namespace std;
bool check(long long int a[],int n,int mid,int h)
{
	long long count=0;
	for(int i=0;i<n;i++)
	{
		count+=a[i]/mid;
		if(a[i]%mid)
		count++;
	}
	return (count<=h);
	
}
int main()
{
	int i,j,n,t;
	cin>>t;
	while(t--)
	{
		long long h,k;
	cin>>n>>h;
 
	long long int a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	
int start=1,end=a[n-1];
while(start<=end)
{
	int mid=(start+end)/2;
	if(check(a,n,mid,h))
	{
		k=mid;
		end=mid-1;
	}
	else
	start=mid+1;
}
cout<<k<<endl;	
	}
} 
