#include <bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define debug 0

using namespace std;

//Extension of Moore's Voting Algorithm

int find_one_third_majority(int ar[], int n){
	
	if(n<=3){
		return -1;
	}
	
	int count1=0, count2=0;
	int a=ar[0];
	int b=ar[1];
	
	for(int i=2;i<n;i++){
		if(ar[i]==a){
			count1++;
		}
		else if(ar[i]==b){
			count2++;
		}
		else if(count1==0){
			a=ar[i];
			count1=1;
		}
		else if(count2==0){
			b=ar[i];
			count2=1;
		}
		else{
			count1--;
			count2--;
		}
	}
	
	count1=count2=0;
	
	for(int i=0;i<n;i++){
		if(ar[i]==a){
			count1++;
		}
		else if(ar[i]==b){
			count2++;
		}
	}
	
	if(count1 > n/3){
		return a;
	}
	
	if(count2 > n/3){
		return b;
	}
	
	return -1;
}


int main() {
	
    int n,i;
	
	cin>>n;
	
	int ar[n];
	
	for(i=0;i<n;i++){
		cin>>ar[i];
	}
	
	cout<<find_one_third_majority(ar,n);
	
	return 0;
}