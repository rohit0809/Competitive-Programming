#include <bits/stdc++.h>

using namespace std;

void heapify(int ar[], int n, int idx){
	int maxm = idx;
	int l = 2*idx + 1;
	int r = 2*idx + 2;
	
	if(l<n && ar[l] > ar[maxm]){
		maxm=l;
	}
	
	if(r<n && ar[r] > ar[maxm]){
		maxm=r;
	}
	
	if(maxm != idx){
		swap(ar[idx],ar[maxm]);
		heapify(ar,n,maxm);
	}
}


void heapsort(int ar[], int n){
	
	// Building max heap
	for(int i = n/2 - 1; i>=0; i--){
		heapify(ar,n,i);
	}
	
	for(int i = n-1; i>=0; i--){
		swap(ar[0],ar[i]);
		heapify(ar,i,0); // heapify reduced heap to get next max;
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

    heapsort(ar,n);

    //Sorted Array
    for(i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }

    return 0;
}