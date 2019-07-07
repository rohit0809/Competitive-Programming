#include <bits/stdc++.h>
using namespace std;

/*
Partition into 2 sets such that difference is minimized.
*/


int main(){
    int n,i,j,sum=0;
    string str1, str2;
    
    cin>>n;
    
    int ar[n+1];
    
    for(i=1;i<=n;i++){
    	cin>>ar[i];
    	sum+=ar[i];
	}
	
	bool dp[n+1][sum+1];
	
	
	for(i=0;i<=n;i++){
		dp[i][0] = true;
	}
	
	for(i=1;i<=sum;i++){
		dp[0][i] = false;
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=sum;j++){
			dp[i][j] = dp[i-1][j];  // excluding
			
			if(ar[i] <= j){
				dp[i][j]|= dp[i-1][j-ar[i]]; // including 
			}
		}
	}
	
	int ans = INT_MAX;
	
	for(j=sum/2;j>=0;j--){
		if(dp[n][j]){
			ans = sum - 2*j;
			break;
		}
	}
	
	cout<<ans;
    
    return 0;
}