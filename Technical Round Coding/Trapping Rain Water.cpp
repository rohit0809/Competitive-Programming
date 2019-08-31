#include <bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define debug 0

using namespace std;

//Rainwater Trapping

int solve(int ar[], int n){
	int right[n+1];
	int left[n+1];
	
	left[0]=ar[0];
	
	for(int i=1;i<n;i++){
		left[i]=max(left[i-1],ar[i]);
	}
	
	right[n-1]=ar[n-1];
	
	for(int i=n-2;i>=0;i--){
		right[i]=max(right[i+1],ar[i]);
	}
	
	int ans=0;
	
	for(int i=0;i<n;i++){
		ans+=(min(left[i],right[i])-ar[i]);
	}
	
	return ans;
}

int solve_space_opti(int ar[], int n){
	int ans=0;
	int left_max=0, right_max=0;
	
	int l=0;
	int r=n-1;
	
	while(l<=r){
		if(ar[l]<ar[r]){
			if(ar[l]>left_max){
				left_max=ar[l];
			}
			else{
				ans+=left_max-ar[l];
			}
			l++;
		}
		else{
			if(ar[r]>right_max){
				right_max=ar[r];
			}
			else{
				ans+=right_max-ar[r];
			}
			r--;
		}
	}
	
	return ans;
}



int main() {
	
    int n,i;
	
	cin>>n;
	
	int ar[n];
	
	for(i=0;i<n;i++){
		cin>>ar[i];
	}
	
	cout<<solve(ar,n)<<" "<<solve_space_opti(ar,n);
	
	return 0;
}