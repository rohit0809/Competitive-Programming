#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,i,j;
    string str1, str2;
    
	cin>>n;
	
	int dp[n];
	int ar[n];
	
	for(i=0;i<n;i++){
		cin>>ar[i];
		dp[i]=1;		// LIS of length 1
	}
	
	
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(ar[i] > ar[j] && (dp[j]+1) > dp[i]){
				dp[i] = dp[j] + 1;
			}
		}
	}
	
	int max_len = 1;
	
	for(i=0;i<n;i++){
		max_len = max(max_len, dp[i]);
	}
	
	cout<<max_len;
    
    return 0;
}