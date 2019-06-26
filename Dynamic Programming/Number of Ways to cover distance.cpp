#include <bits/stdc++.h>
using namespace std;

/*
Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps.
*/


int main(){
    int n,i,j,sum=0;
    string str1, str2;
    
    cin>>n;
    
    int dp[n+1];
    
    dp[0]=dp[1]=1;
    dp[2]=2;
    
    for(i=3;i<=n;i++){
    	dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	
	cout<<dp[n];
    
    return 0;
}