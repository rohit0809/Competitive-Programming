#include <bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define debug 0

using namespace std;

//Catalan Number DP

int catalan(int n){
	
	int dp[n+1];
	
	dp[0]=dp[1]=1;
	
	for(int i=2;i<=n;i++){
		dp[i]=0;
		for(int j=0;j<i;j++){
			dp[i]+=(dp[j]*dp[i-j-1]);
		}
	}
	
	return dp[n];
	
}

int main() {
    
	int n,i;
	
	cin>>n;
	
	cout<<catalan(n);
  
	
	return 0;
}