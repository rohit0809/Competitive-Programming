#include <bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define debug 0

using namespace std;

// O(n^2) LIS DP Solution

int solve(int ar[], int n){
	int dp[n];
	
	dp[0]=1;
	
	for(int i=1;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(ar[i]>ar[j] && dp[i]<(dp[j]+1)){
				dp[i]=dp[j]+1;
			}
		}
	}
	
	return *max_element(dp,dp+n);
	
}

// O(nlogn) LIS Binary Search Solution

int bsearch(vector<int> &tail, int l, int r, int key){
	while(r-l > 1){
		int mid = l + (r-l)/2;
		if(tail[mid]>= key){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	
	return r;
}

int solve_opti(int ar[], int n){
	
	vector<int> tail(n,0);
	int len = 1;
	
	tail[0]=ar[0];
	
	for(int i=1;i<n;i++){
		if(ar[i]<tail[0]){
			tail[0]=ar[i];
		}
		else if(ar[i]>tail[len-1]){
			tail[len++]=ar[i];
		}
		else{
			tail[bsearch(tail,-1,len-1,ar[i])]=ar[i];
		}
	}
	
	return len;
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