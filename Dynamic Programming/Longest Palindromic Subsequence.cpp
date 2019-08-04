class Solution {
public:
    int longestPalindromeSubseq(string str) {
        int len = str.length();
        
        if(len<=1){
            return len;
        }
        
        int dp[len+1][len+1];
        
        for(int i=0;i<=len;i++){
            for(int j=0;j<=len;j++){
                dp[i][j]=0;
            }
        }
        
        for(int i=0;i<len;i++){
            dp[i][i]=1;
        }
        
        for(int k=2;k<=len;k++){
            for(int i=0;i<len-k+1;i++){
                int j=i+k-1;
                if(str[i]==str[j] && k==2){
                    dp[i][j]=2;
                }
                else if(str[i]==str[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        
        return dp[0][len-1];
    }
};