#include <bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define debug 0

using namespace std;

// O(n^2) DP Solution

int solve(int ar[], int n){
	if(n==0 || ar[0]==0){
		return INT_MAX;
	}
	
	int dp[n+1];
	
	dp[0]=0;
	
	for(int i=1;i<n;i++){
		dp[i]=INT_MAX;
		for(int j=0;j<i;j++){
			if((j+ar[j])>=i && dp[j]!=INT_MAX){
				dp[i]=min(dp[i],dp[j]+1);
			}
		}
	}
	
	return dp[n-1];
}

// O(n) Greedy solution

int solve_opti(int ar[], int n){
	if(n<=1){
		return 0;
	}
	
	if(ar[0]==0){
		return INT_MAX;
	}
	
	int max_reach = ar[0];
	int steps = ar[0];
	int jump = 1;
	
	for(int i=1;i<n;i++){
		if(i==n-1){
			return jump;
		}
		
		max_reach=max(max_reach,ar[i]+i);
		
		steps--;
		
		if(steps == 0){
			jump++;
			
			if(i>=max_reach){
				return INT_MAX;
			}
			
			steps = max_reach - i;
		}
	}
	
	return INT_MAX;
}


int main() {
	
    int n,i,k;
	
	cin>>n;
	
	int ar[n];
	
	for(i=0;i<n;i++){
		cin>>ar[i];
	}
	
	cout<<solve(ar,n)<<"  "<<solve_opti(ar,n);
	
	return 0;
}