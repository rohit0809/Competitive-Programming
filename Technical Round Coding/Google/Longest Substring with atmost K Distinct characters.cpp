class Solution {
public:
    static bool compare(pair<char,int> a, pair<char,int> b){
        return a.second <  b.second;
    }
    int lengthOfLongestSubstringKDistinct(string str, int k) {
        int len = str.length();
        
        if(len<k){
            return len;
        }
        
        int i=0, maxm=k, start=0;
        map<char,int> has;
        map<char,int>::iterator it;
        
        while(i<len){
            if(has.size()<k+1){
                has[str[i]]=i;
                i++;
            }
            
            if(has.size()==k+1){
                pair<char,int> pr = *min_element(has.begin(),has.end(),compare);
                start=pr.second+1;
                has.erase(pr.first);
            }
            
            maxm=max(maxm,i-start);
        }
        
        return maxm;
    }
};