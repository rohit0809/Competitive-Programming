#include <bits/stdc++.h>
class Solution {
public:
    static bool compare(pair<char,int> a, pair<char,int> b){
        return a.second <  b.second;
    }
    int lengthOfLongestSubstringTwoDistinct(string str) {
        int len = str.length();
        
        if(len<3){
            return len;
        }
        
        int i=0, maxm=2, start=0;
        map<char,int> has;
        map<char,int>::iterator it;
        
        while(i<len){
            if(has.size()<3){
                has[str[i]]=i;
                i++;
            }
            
            if(has.size()==3){
                pair<char,int> pr = *min_element(has.begin(),has.end(),compare);
                start=pr.second+1;
                has.erase(pr.first);
            }
            
            maxm=max(maxm,i-start);
        }
        
        return maxm;
        
    }
};