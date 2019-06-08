#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,i,j;
    bool is_swapped;

    cin>>n;

    for(i=0;i<n;i++){
        cin>>ar[i];
    }

    for(i=0;i<n-1;i++){
        is_swapped = false;
        for(j=0;j<n-i-1;j++){
            if(ar[j]>ar[j+1]){
                swap(ar[j],ar[j+1]);
                is_swapped = true;
            }
        }

        if(!is_swapped){
            break; // array is sorted now
        }
    }

    //Sorted Array
    for(i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }

    return 0;
}