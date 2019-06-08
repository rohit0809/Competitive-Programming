#include <bits/stdc++.h>

using namespace std;

void merge(int ar[], int low, int mid, int high){
	int l1 = mid - low + 1;
	int l2 = high - mid;
	int left_part[l1], right_part[l2];
	
	for(int i=0;i<l1;i++){
		left_part[i]=ar[low+i];
	}
	
	for(int i=0;i<l2;i++){
		right_part[i]=ar[mid+1+i];
	}
	
	int i=0, j=0, k=low;
	
	while(i<l1 || j<l2){
		if(j==l2 && i<l1){
			ar[k++]=left_part[i++];
			continue;
		}
		if(i==l1 && j<l2){
			ar[k++]=right_part[j++];
			continue;
		}
		
		if(left_part[i]<=right_part[j]){
			ar[k++]=left_part[i++];
		}
		else{
			ar[k++]=right_part[j++];
		}
	}
}


void mergesort(int ar[], int low, int high){
	if(low < high){
		int mid = low + (high-low)/2 ;
		mergesort(ar,low,mid);
		mergesort(ar,mid+1,high);
		merge(ar,low,mid,high);
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

    mergesort(ar,0,n-1);

    //Sorted Array
    for(i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }

    return 0;
}