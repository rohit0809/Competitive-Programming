#include <bits/stdc++.h>
using namespace std;

/*Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace
All of the above operations are of equal cost. */


int main(){
    int n,i,j;
    string str1, str2;
    
	cin>>str1;
	cin>>str2;
	
	int len1 = str1.length();
	int len2 = str2.length();
	
	int dp[len1+1][len2+1];
	
	for(i=0;i<=len1;i++){
		for(j=0;j<=len2;j++){
			if(i==0){
				dp[i][j]=j;
			}
			else if(j==0){
				dp[i][j]=i;
			}
			else if(str1[i-1]==str2[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j], dp[i-1][j-1]));
			}
		}
	}
	
	int edits = dp[len1][len2];
	
	cout<<edits;
    
    return 0;
}