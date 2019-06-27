#include <bits/stdc++.h>
using namespace std;

/*
Subset Sum Problem
*/



int main(){
    int n,i,j,sum=0;
    string str1, str2;
    
    cin>>n;
    
    int ar[n+1];
    
    for(i=0;i<n;i++){
    	cin>>ar[i];
	}
	
	cin>>sum;
	
	bool dp[n+1][sum+1];
	
	for(i=0;i<=n;i++){
		dp[i][0]=1;
	}
	
	for(i=1;i<=sum;i++){
		dp[0][i]=0;
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=sum;j++){
			dp[i][j] = dp[i-1][j]; // Excluding
			
			if(j>=ar[i-1]){
				dp[i][j] |= dp[i-1][j-ar[i-1]];  // Including
			}
		}
	}
	
	bool ans = dp[n][sum];
	
	if(ans){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
    
    return 0;
}