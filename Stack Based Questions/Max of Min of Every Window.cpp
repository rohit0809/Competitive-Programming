#include <bits/stdc++.h>
using namespace std;

// Maximum of Minimum of every window size


int main(){
	
	int i,n;
	
	cin>>n;
	
	int ar[n+1];
	int rse[n+1];  // Next smaller on right side
	int lse[n+1]; // Previous smaller on left side
	
	for(int i=0;i<n;i++){
		cin>>ar[i];
		rse[i]=n;
		lse[i]=-1;
	}
	
	stack<int> stk;
	
	for(i=n-1;i>=0;i--){
		while(!stk.empty() && ar[i]<=ar[stk.top()]){
			stk.pop();
		}
		
		if(!stk.empty()){
			rse[i]=stk.top();
		}
		
		stk.push(i);
	}
	
	while(!stk.empty()){
		stk.pop();
	}
	
	for(i=0;i<n;i++){
		while(!stk.empty() && ar[i]<=ar[stk.top()]){
			stk.pop();
		}
		
		if(!stk.empty()){
			lse[i]=stk.top();
		}
		
		stk.push(i);
	}
	
	int ans[n+1];
	
	for(i=0;i<=n;i++){
		ans[i]=0;
	}
	
	for(i=0;i<n;i++){
		int len = rse[i]-lse[i]-1;
		ans[len] = max(ans[len],ar[i]);
	}
	
	for(i=n-1;i>=1;i--){
		ans[i]=max(ans[i],ans[i+1]);
	}
	
	for(i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	

	return 0;
}