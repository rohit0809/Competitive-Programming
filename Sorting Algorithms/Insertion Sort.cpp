#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,i,j,key;
    bool is_swapped;

    cin>>n;
    
    int ar[n];

    for(i=0;i<n;i++){
        cin>>ar[i];
    }

    for(i=0;i<n;i++){
        j=i-1;
        key=ar[i];
        while(j>=0 && ar[j] > key){  // insert at right place
        	ar[j+1]=ar[j];
        	j--;
		}
		ar[j+1]=key;
    }

    //Sorted Array
    for(i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }

    return 0;
}