//@author rohit_0809 --codeforces rohit_0801 --codechef  rohit_0809 hackerearth  (ROHIT ANAND)
/*
There are total n people in a party. Every person might or might not know other person by name. But, Every person know a single person out of n persons.
But that single person didnt know any other person by name.
Find that single person.
*/

#include <bits/stdc++.h>
using namespace std;

bool solve(int a, int b){
	int know = rand()%2;
	return know ? 1: 0;
}


int main() {
	srand(time(0));
   	int n,i,a,b,ans;
   	i=1;    
	a=i;
	b=i+1;
	cin>>n;
	for(i=3;i<=n+1;i++){
		if(solve(a,b)){  // a knows b => a is not celebrity
			a=i;
			ans=b;
		}
		else{  // a dont know b => b is not celebrity
			b=i;
			ans=a;
		}
	}
	
	cout<<ans; // total questions asked = n-1
	
	return 0;
}