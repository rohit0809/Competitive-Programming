#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int i,n;
	
	cin>>n;
	
	int ar[n+1];
	int nse[n+1];  // Next smaller on right side
	
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		nse[i]=-1;
	}
	
	stack<int> stk;
	
	for(i=n;i>=1;i--){
		while(!stk.empty() && ar[i]<ar[stk.top()]){
			stk.pop();
		}
		
		if(!stk.empty()){
			nse[i]=stk.top();
		}
		
		stk.push(i);
	}
	
	for(i=1;i<=n;i++){
		if(nse[i]!=-1){
			cout<<ar[nse[i]]<<" ";
		}
		else{
			cout<<nse[i]<<" ";
		}
	}
	
	cout<<"\n";
	

	return 0;
}