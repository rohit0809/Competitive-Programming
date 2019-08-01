#include <bits/stdc++.h>
using namespace std;

// Search element in sorted and rotated array

int solve(int ar[], int l, int h, int key){
	if(h<l){
		return -1;
	}
	
	int mid = l + (h-l)/2;
	
	if(ar[mid]==key){
		return key;
	}
	
	if(ar[l]<=ar[mid]){
		if(key>=ar[l] && key<=ar[mid]){
			return solve(ar,l,mid-1,key);
		}
		
		return solve(ar,mid+1,h,key);
	}
	
	if(key>=ar[mid] && key<=ar[h]){
		return solve(ar,mid+1,h,key);
	}
	
	return solve(ar,l,mid-1,key);
}


int main(){
	
	int i,n,k;
	
	cin>>n;
	
	int ar[n+1];
	
	for(i=0;i<n;i++){
		cin>>ar[i];
	}
	
	cin>>k;
	
	cout<<solve(ar,0,n-1,k);
	

	return 0;
}