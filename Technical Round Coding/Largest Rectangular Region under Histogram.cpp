#include <bits/stdc++.h>
using namespace std;

// Largest Rectangular Area Under Histogram


int main(){
	
	int i,n,k;
	
	cin>>n;
	
	int ar[n+1];
	
	for(i=0;i<n;i++){
		cin>>ar[i];
	}
	
	stack<int> stk;
	
	i=0;
	int max_area = 0;
	
	while(i<n){
		if(stk.empty() || ar[i]>=ar[stk.top()]){
			stk.push(i++);
		}
		else{
			int p = stk.top();
			stk.pop();
			
			int area = ar[p] * (stk.empty() ? i : i - stk.top() - 1);
			
			max_area = max(max_area, area);
		}
	}
	
	while(!stk.empty()){
		int p = stk.top();
		stk.pop();
		
		int area = ar[p] * (stk.empty() ? i : i - stk.top() - 1);
		
		max_area = max(max_area, area);
	}
	
	cout<<max_area;
	

	return 0;
}