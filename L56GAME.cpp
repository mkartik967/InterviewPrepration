#include <iostream>
using namespace std;
 
int main()
{
	int i,j,k,n,t;
	cin>>t;
	while(t--)
	{
		int odd=0;
		int even=0;
		cin>>n;
		while(n--)
		{
			cin>>k;
			if(k%2)
			odd++;
			else
			even++;
		}
		cout<<odd%2+1<<endl;
	}
}
