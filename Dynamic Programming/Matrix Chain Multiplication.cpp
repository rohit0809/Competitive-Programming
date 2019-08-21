#include <bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define debug 0

using namespace std;

//Matrix Chain Multiplication

int solve(int ar[], int n){
	
	int dp[n+1][n+1];
	
	for(int i=1;i<n;i++){
		dp[i][i]=0;
	}
	
	for(int i=2;i<n;i++){
		for(int j=1;j<n-i+1;j++){
			int d=j+i-1;
			dp[j][d]=INT_MAX;
			for(int k=j;k<=d-1;k++){
				int val = dp[j][k] + dp[k+1][d] + ar[j-1]*ar[k]*ar[d];
				if(val<dp[j][d]){
					dp[j][d]=val;
				}
			}
		}
	}
	
	return dp[1][n-1];
	
}

int main() {
    
	int n,i;
	
	cin>>n;
	
	int ar[n+1];
	
	for(i=0;i<n;i++){
		cin>>ar[i];
	}
	
	cout<<solve(ar,n);
  
	
	return 0;
}