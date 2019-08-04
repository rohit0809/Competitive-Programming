#include <bits/stdc++.h>
using namespace std;

int maxProfitWithKTransactions(vector<int> prices, int k) {
  // Write your code here.
	int dp[k+1][prices.size()+1];
	
	for(int i=0;i<=k;i++){
		for(int j=0;j<=prices.size();j++){
			dp[i][j]=0;
		}
	}
	
	for(int i=1;i<=k;i++){
		int maxm = INT_MIN;
		for(int j=1;j<prices.size();j++){
			maxm=max(maxm,dp[i-1][j-1]-prices[j-1]);
			dp[i][j]=max(dp[i][j-1],maxm+prices[j]);
		}
	}
	
	return dp[k][prices.size()-1];
	
}
