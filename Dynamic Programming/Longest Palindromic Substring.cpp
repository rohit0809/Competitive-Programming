class Solution {
public:
    string longestPalindrome(string str) {
        int len = str.length();
        int maxm = 1;
        string ans = "";
        int strt=0;
        
        bool dp[len+2][len+2] = {{0}};
        
        for(int i=0;i<len;i++){
            dp[i][i]=1;
            maxm=1;
            strt=i;
        }
        
        for(int i=0;i<len-1;i++){
            if(str[i]==str[i+1]){
                dp[i][i+1]=1;
                maxm=2;
                strt=i;
            }
        }
        
        for(int k=3;k<=len;k++){
            for(int i=0;i<len-k+1;i++){
                int j = i+k-1;
                if(str[i]==str[j] && dp[i+1][j-1]){
                    dp[i][j]=1;
                    if(k>maxm){
                        maxm=k;
                        strt=i;
                    }
                }
            }
        }
        
        return str.substr(strt,maxm);
    }
};