#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int t,i,j,n;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		n=s.length();
		i=0;
		int count=0;
		while(i<n-3)
		{
			string ans="";
			ans+=s[i];
			ans+=s[i+1];
			ans+=s[i+2];
			ans+=s[i+3];
			sort(ans.begin(),ans.end());
		//	cout<<ans<<endl;
			if(ans.compare("cefh")==0)
			count++;
			i++;
		}
		if(!count)
		cout<<"normal"<<endl;
		else
		cout<<"lovely "<<count<<endl;
	}
	
}
