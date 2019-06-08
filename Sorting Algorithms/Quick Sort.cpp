#include <bits/stdc++.h>

using namespace std;

int partition(int ar[], int low, int high){
	int idx = low-1;
	int partition_element = ar[high];
	
	for(int j=low;j<high;j++){
		if(ar[j]<=partition_element){
			idx++;
			swap(ar[idx],ar[j]);
		}
	}
	
	swap(ar[idx+1],ar[high]);
	return idx+1;
}


void quicksort(int ar[], int low, int high){
	if(low < high){
		int partition_idx = partition(ar,low,high); // Fix the right position in sorted array
		quicksort(ar,low,partition_idx-1);
		quicksort(ar,partition_idx+1,high);
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

    quicksort(ar,0,n-1);

    //Sorted Array
    for(i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }

    return 0;
}