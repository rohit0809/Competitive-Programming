#include "bits/stdc++.h"
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int len = str.length();
        if(len==0){
            return 0;
        }
        unordered_map<char,int> has;
        
        int start = 0, maxm=0;
        for(int i=0;i<len;i++){
            if(has.find(str[i])!=has.end()){
                start=max(start,has[str[i]]);
            }
            maxm=max(maxm,i-start+1);
            has[str[i]]=i+1;
        }
        return maxm;
    }
};