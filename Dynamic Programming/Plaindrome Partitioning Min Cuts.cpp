#include <bits/stdc++.h>
using namespace std;

int palindromePartitioningMinCuts(string str) {
  // Write your code here.
	int len = str.length();
	bool pal[len+1][len+1];
	
		for(int i=0;i<=len;i++){
			for(int j=0;j<=len;j++){
				pal[i][j]=0;
			}
		}
	
	for(int i=0;i<len;i++){
		pal[i][i]=1;
	}
	
	for(int i=0;i<len-1;i++){
		if(str[i]==str[i+1]){
			pal[i][i+1]=1;
		}
	}
	
	for(int k=3;k<=len;k++){
		for(int i=0;i<len-k+1;i++){
			int j=i+k-1;
			if(str[i]==str[j] && pal[i+1][j-1]){
				pal[i][j]=1;
			}
		}
	}
	
	int dp[len+1];
	
	for(int i=0;i<len;i++){
		dp[i]=99999;;
	}
	
	
	for(int i=0;i<len;i++){
		if(pal[0][i]){
			dp[i]=0;
		}
		else{
			dp[i]=dp[i-1]+1;
			for(int j=1;j<i;j++){
				if(pal[j][i] && dp[j-1] + 1 < dp[i]){
					dp[i]=dp[j-1]+1;
				}
			}
		}
	}
	
	return dp[len-1];
}
