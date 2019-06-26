#include <bits/stdc++.h>
using namespace std;

/*
Given a n*n matrix where all numbers are distinct, 
find the maximum length path (starting from any cell) such that all cells along the path are in increasing order with a difference of 1
*/

int mat[1001][1001];
int dp[1001][1001];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int solve(int x, int y, int n){
	if(dp[x][y]!=-1){
		return dp[x][y];
	}
	
	for(int i=0;i<4;i++){
		int p = x+dx[i];
		int q = y+dy[i];
		
		if(p<=n && p>=1 && q<=n && q>=1){
			if((mat[p][q]+1) == mat[x][y]){
				return dp[x][y] = 1 + solve(p,q,n);
			}
		}
	}
	
	return dp[x][y] = 1;
}


int main(){
    int n,i,j,sum=0;
    string str1, str2;
    
    cin>>n;
    
    for(i=1;i<=n;i++){
    	for(j=1;j<=n;j++){
    		cin>>mat[i][j];
		}
	}
	
	memset(dp,-1,sizeof(dp));
	
	int ans = INT_MIN;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(dp[i][j] == -1){
				ans = max(ans,solve(i,j,n));
			}
		}
	}
	
	cout<<ans<<"\n";
    
    return 0;
}