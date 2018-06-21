#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int t,i,j,n,m,x,k;
	cin>>t;
	while(t--)
	{
	string s;
	cin>>s;
	n=s.length();
	if(n==1)
	{
		cout<<1<<endl;
		continue;
	}
	vector<int>graph[26];
	vector<int>v1,v2;
	bool flag=1;
for(i=0;i<n;i++)
graph[s[i]-97].push_back(i+1);
if(n%2)
{
	m=-1;
	for(i=0;i<26;i++)
	{
		if(graph[i].size())
		{
			if(graph[i].size()%2)
			{
				m=graph[i][0];
				for(j=1;j<graph[i].size();j+=2)
				{
					v1.push_back(graph[i][j]);
					v2.push_back(graph[i][j+1]);
				}
 
		}
			else 
			{
				for(j=0;j<graph[i].size();j+=2)
				{
					v1.push_back(graph[i][j]);
					v2.push_back(graph[i][j+1]);
				}
				
			}
			
		}
	}
	k=v1.size()+v2.size();
	if(m!=-1)
	k++;
	if(k!=n)
	flag=0;
	if(!flag)
	{
		cout<<-1<<endl;
		continue;
	}
for(j=0;j<v1.size();j++)
cout<<v1[j]<<" ";
if(m!=-1)
cout<<m<<" ";
for(j=0;j<v2.size();j++)
cout<<v2[v2.size()-j-1]<<" ";
 
}
else{
	for(i=0;i<26;i++)
	{
	
			if(graph[i].size()%2)
			{
					flag=0;
					break;
				}
			else 
			{
				for(j=0;j<graph[i].size();j+=2)
				{
					v1.push_back(graph[i][j]);
					v2.push_back(graph[i][j+1]);
				}
				
			}
	}
	if(!flag)
	{
		cout<<-1<<endl;
		continue;
	}
for(j=0;j<v1.size();j++)
cout<<v1[j]<<" ";
for(j=0;j<v2.size();j++)
cout<<v2[v2.size()-j-1]<<" ";
 
}
cout<<endl;
 
	}
	
}
 
