#include <bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define debug 0

using namespace std;

//Cutting Rod DP
// maximize profit

int solve(int ar[], int n){
	
	int dp[n+1];
	
	dp[0]=0;
	
	for(int i=1;i<=n;i++){
		dp[i]=INT_MIN;
		for(int j=0;j<i;j++){
			dp[i]=max(dp[i],ar[j]+dp[i-j-1]);
		}
	}
	
	return dp[n];
	
}

int main() {
	
    
	int n,i;
	
	cin>>n;
	
	int ar[n];
	
	for(i=0;i<n;i++){
		cin>>ar[i];
	}
	
	cout<<solve(ar,n);
  
	
	return 0;
}