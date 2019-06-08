#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,i,j,min_idx;
    bool is_swapped;

    cin>>n;
    
    int ar[n];

    for(i=0;i<n;i++){
        cin>>ar[i];
    }

    for(i=0;i<n-1;i++){
    	min_idx = i;
    	for(j=i+1;j<n;j++){
    		if(ar[j] < ar[min_idx]){
    			min_idx = j;
			}
		}
		swap(ar[min_idx],ar[i]); // place the minimum element at right index
	}

    //Sorted Array
    for(i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }

    return 0;
}