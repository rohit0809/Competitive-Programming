#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
  // Write your code here.
	int siz = array.size();
	
	if(siz==0){
		return 0;
	}
	
	if(siz==1){
		return array[0];
	}
	
	if(siz==2){
		return max(array[0],array[1]);
	}
	
	int dp[siz+2];
	dp[1]=array[0];
	dp[2]=max(array[0],array[1]);
	for(int i=3;i<=siz;i++){
		dp[i]=max(array[i-1]+dp[i-2], dp[i-1]);
	}
	
	return dp[siz];
}
