#include <bits/stdc++.h>
using namespace std;

// Minimum element in sorted and rotated array

int solve(int ar[], int l, int h){
	if(h<l){
		return ar[0];
	}
	
	if(h==l){
		return ar[h];
	}
	
	int mid = l + (h-l)/2;
	
	if(mid < h && ar[mid+1]<ar[mid]){
		return ar[mid+1];
	}
	
	if(mid > l && ar[mid] < ar[mid-1]){
		return ar[mid];
	}
	
	if(ar[h]>ar[mid]){
		return solve(ar,l,mid-1);
	}
	
	return solve(ar,mid+1,h);
}


int main(){
	
	int i,n;
	
	cin>>n;
	
	int ar[n+1];
	
	for(i=0;i<n;i++){
		cin>>ar[i];
	}
	
	cout<<solve(ar,0,n-1);
	

	return 0;
}