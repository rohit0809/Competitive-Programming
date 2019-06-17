#include <bits/stdc++.h>
using namespace std;


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
			if(i==0 || j==0){
				dp[i][j]=0;
			}
			else if(str1[i-1] == str2[j-1]){
				dp[i][j]=dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	int lcs = dp[len1][len2];
	
	cout<<lcs;
    
    return 0;
}