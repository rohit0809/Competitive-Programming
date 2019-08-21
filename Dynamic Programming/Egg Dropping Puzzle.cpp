#include <bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define debug 0

using namespace std;

//Egg Dropping Puzzle
//n eggs, k floors

int solve(int n, int k){
	int dp[n+1][k+1];
	
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
		dp[i][1]=1;
	}
	
	for(int i=0;i<=k;i++){
		dp[1][i]=i;
	}
	
	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++){
			dp[i][j]=INT_MAX;
			for(int x=1;x<=j;x++){
				int val = 1 + max(dp[i-1][x-1],dp[i][j-x]);
				if(val<dp[i][j]){
					dp[i][j]=val;
				}
			}
		}
	}
	
	return dp[n][k];
	
}

int main() {
    
	int n,k;
	
	cin>>n>>k;
	
	cout<<solve(n,k);
  
	
	return 0;
}