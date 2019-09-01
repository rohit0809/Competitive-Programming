#include <bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define debug 0

using namespace std;

// Binary Search the answer

bool check(int ar[], int val, int n, int k){
	int sum=0;
	int count=0;
	
	for(int i=0;i<n;i++){
		if(ar[i]>val){
			return false;
		}
		sum+=ar[i];
		if(sum>val){
			count++;
			sum=ar[i];
		}
	}
	
	count++;
	
	if(count<=k){
		return true;
	}
	
	return false;
}

//Minimize the maximum sum of splitting into k Sub-arrays

int solve(int ar[], int n, int k){
	int sum=0;
	
	for(int i=0;i<n;i++){
		sum+=ar[i];
	}
	
	int l=1;
	int r=sum;
	
	int ans;
	
	while(l<=r){
		int mid = l + (r-l)/2;
		
		if(check(ar,mid,n,k)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	
	return ans;
}




int main() {
	
    int n,i,k;
	
	cin>>n;
	
	int ar[n];
	
	for(i=0;i<n;i++){
		cin>>ar[i];
	}
	
	cin>>k;
	
	cout<<solve(ar,n,k);
	
	
	return 0;
}