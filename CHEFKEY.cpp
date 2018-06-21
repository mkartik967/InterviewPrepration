#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,q,c,t;
	cin>>t;
	while(t--){
		int count=0;
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++){
			if(c%i==0&&c/i<=m)
		q=c/i;
	else
	continue;
		for(int j=1;j<=m;j++){
			if(q%j==0){
			count++;
			break;
	}
}
}
	cout<<count<<endl;
}
}
