#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	int result;
	int a[3];
	cin>>t;
	while(t--){
	
	int r,g,b,k;long long int ans=0;
	cin>>a[0]>>a[1]>>a[2]>>k;
	sort(a,a+3);
	if(k==1)
	ans=1;
	else 
	
	{
	if(k>a[0])
	{
		ans+=a[0];
		if(k>a[1])
		ans+=a[1];
		else 
		ans+=(k-1);
	}
	else
	ans+=2*k-2;
	
	
	 ans=ans+k;
}
	cout<<ans<<endl;
 
}
} 
