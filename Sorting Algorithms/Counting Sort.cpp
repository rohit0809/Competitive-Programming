#include <bits/stdc++.h>
using namespace std;

void countsort(int ar[], int n){
	int minm = *min_element(ar,ar+n);
	int maxm = *max_element(ar,ar+n);
	int lim = maxm - minm + 1;
	int count_ar[lim+1] = {0};
	int output_index[lim+1] = {0};
	
	for(int i=0;i<n;i++){
		count_ar[ar[i]-minm]++;  // handles negative numbers also
	}
	
	for(int i=1;i<=lim;i++){
		count_ar[i]+=count_ar[i-1];
	}
	
	// Stable Algorithm
	for(int i=n-1;i>=0;i--){
		output_index[count_ar[ar[i]-minm]-1]=ar[i];
		count_ar[ar[i]-minm]--;
	}
	
	for(int i=0;i<n;i++){
		ar[i]=output_index[i];
	}
}

int main(){
    int n,i,j,min_idx;
    bool is_swapped;

    cin>>n;
    
    int ar[n];

    for(i=0;i<n;i++){
        cin>>ar[i];
    }

    countsort(ar,n);

    //Sorted Array
    for(i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }

    return 0;
}