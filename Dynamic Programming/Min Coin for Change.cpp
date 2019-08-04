#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  // Write your code here.
	int dp[n+1];
	for(int i=0;i<=n;i++)
		dp[i]=INT_MAX;
	
	dp[0]=0;
	
	for(int i=0;i<denoms.size();i++){
		for(int j=denoms[i];j<=n;j++){
			if(dp[j-denoms[i]]==INT_MAX)
				dp[j]=min(dp[j],dp[j-denoms[i]]);
			else
				dp[j]=min(dp[j],1+dp[j-denoms[i]]);
		}
	}
	
	return dp[n]==INT_MAX ? -1 : dp[n];
	
}
