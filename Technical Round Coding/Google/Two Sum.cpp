class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> has,pos;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            has[nums[i]]++;
            pos[nums[i]]=i;
        }
        
        for(int i=0;i<nums.size();i++){
            if(target-nums[i] == nums[i] && has[target-nums[i]]>1){
                ans.push_back(i);
                ans.push_back(pos[nums[i]]);
                break;
            }
            else if(target-nums[i] != nums[i] && has[target-nums[i]]>0){
                ans.push_back(i);
                ans.push_back(pos[target-nums[i]]);
                break;
            }
        }
        
        return ans;
    }
};