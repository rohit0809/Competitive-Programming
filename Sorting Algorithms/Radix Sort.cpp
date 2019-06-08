#include <bits/stdc++.h>
using namespace std;

void countsort(int ar[], int n, int exp){
	int lim = 10;
	int count_ar[lim] = {0};
	int output_index[lim] = {0};
	
	for(int i=0;i<n;i++){
		count_ar[(ar[i]/exp)%10]++;  
	}
	
	for(int i=1;i<=lim;i++){
		count_ar[i]+=count_ar[i-1];
	}
	
	// Stable Algorithm
	for(int i=n-1;i>=0;i--){
		output_index[count_ar[(ar[i]/exp)%10]-1]=ar[i];
		count_ar[(ar[i]/exp)%10]--;
	}
	
	for(int i=0;i<n;i++){
		ar[i]=output_index[i];
	}
}

void radixsort(int ar[], int n){
	int maxm = *max_element(ar,ar+n);
	
	for(int exp = 1 ; maxm/exp > 0; exp*=10){
		countsort(ar, n, exp);
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

    radixsort(ar,n);

    //Sorted Array
    for(i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }

    return 0;
}