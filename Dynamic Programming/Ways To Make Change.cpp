#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  // Write your code here.
	int dp[n+2];
	for(int i=0;i<=n;i++)
		dp[i]=0;
	
	dp[0]=1;
	for(int i=0;i<denoms.size();i++){
		for(int j=denoms[i];j<=n;j++){
			dp[j]+=(dp[j-denoms[i]]);
		}
	}
	
	return dp[n];
}
