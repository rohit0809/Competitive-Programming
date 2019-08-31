#include <bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define debug 0

using namespace std;

//Maximum Product Cutting Rod DP

int solve(int n){
	
	int dp[n+1];
	
	dp[0]=dp[1]=0;
	
	for(int i=2;i<=n;i++){
		dp[i]=INT_MIN;
		for(int j=1;j<=i/2;j++){
			dp[i]=max(dp[i],j*(i-j));
			dp[i]=max(dp[i],j*dp[i-j]);
		}
	}

	
	return dp[n];
	
}


// Observation based Greedy Solution
int solve_tricky(int n){
	if(n==2 || n==3)
		return n-1;
		
	int ans=1;
	
	while(n>4){
		n-=3;
		ans*=3;
	}
	
	ans*=n;
	
	return ans;
}

int main() {
	
    int n,i;
	
	cin>>n;
	
	cout<<solve(n)<<"  "<<solve_tricky(n);
  
	
	return 0;
}