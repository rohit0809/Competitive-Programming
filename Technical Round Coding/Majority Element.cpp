#include <bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define debug 0

using namespace std;

//Moore's Voting Algorithm

void find_majority(int ar[], int n){
	int cand = 0;
	int c = 1;
	
	for(int i=1;i<n;i++){
		if(ar[i]==ar[cand]){
			c++;
		}
		else{
			c--;
		}
		
		if(c==0){
			cand=i;
			c=1;
		}
	}
	
	int maj = n/2;
	c=0;
	
	for(int i=0;i<n;i++){
		if(ar[i]==ar[cand]){
			c++;
		}
	}
	
	if(c>maj){
		cout<<ar[cand];
	}
	else{
		cout<<"No Majority Element!!";
	}
}


int main() {
	
    int n,i;
	
	cin>>n;
	
	int ar[n];
	
	for(i=0;i<n;i++){
		cin>>ar[i];
	}
	
	find_majority(ar,n);
	
	return 0;
}