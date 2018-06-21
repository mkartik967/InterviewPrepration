#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	int p,c=0;
		string q,r;
		cin>>p>>q;
		
		while(p--){
			cin>>r;
			if(r=="CONTEST_WON"){
			int a;
				cin>>a;
			if(a<20)
			c=c+300+20-a;
			else
			c=c+300;
}
		else if(r=="TOP_CONTRIBUTOR")
			c=c+300;
		else if(r=="BUG_FOUND"){
		int b;
			cin>>b;
			c=c+b;
		}
		
		else{
			
			c=c+50;
		}
		}
		if(q=="INDIAN")
		cout<<c/200<<endl;
		else
		cout<<c/400<<endl;
	}
} 
