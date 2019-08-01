#include <bits/stdc++.h>
using namespace std;

// Upper Bound in Binary Search

int solve(int ar[], int l, int h, int key, int n){
	if(h>=l){
		int mid = l + (h-l)/2;
		if((mid==n-1 || key < ar[mid+1]) && ar[mid]==key){
			return mid;
		}
		else if(key < ar[mid]){
			return solve(ar,l,mid-1,key,n);
		}
		else{
			return solve(ar,mid+1,h,key,n);
		}
	}
	
	return -1;
}


int main(){
	
	int i,n,k;
	
	cin>>n;
	
	int ar[n+1];
	
	for(i=0;i<n;i++){
		cin>>ar[i];
	}
	
	cin>>k;
	
	cout<<solve(ar,0,n-1,k,n);
	

	return 0;
}