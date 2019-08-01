#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int i,n;
	
	cin>>n;
	
	int ar[n+1];
	int nge[n+1];  // Next greater on right side
	
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		nge[i]=-1;
	}
	
	stack<int> stk;
	
	for(i=n;i>=1;i--){
		while(!stk.empty() && ar[i]>ar[stk.top()]){
			stk.pop();
		}
		
		if(!stk.empty()){
			nge[i]=stk.top();
		}
		
		stk.push(i);
	}
	
	for(i=1;i<=n;i++){
		if(nge[i]!=-1){
			cout<<ar[nge[i]]<<" ";
		}
		else{
			cout<<nge[i]<<" ";
		}
	}
	
	cout<<"\n";
	

	return 0;
}