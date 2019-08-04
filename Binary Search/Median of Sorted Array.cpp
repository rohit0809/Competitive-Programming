class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int n = nums1.size();
        int m = nums2.size();
        int l = 0;
        int h = n;
        
        while(l<=h){
            int partx = l + (h-l)/2;
            int party = (n+m+1)/2 - partx;
            
            int maxX = partx == 0 ? INT_MIN : nums1[partx-1];
            int minX = partx == n ? INT_MAX : nums1[partx];
            
            int maxY = party == 0 ? INT_MIN : nums2[party-1];
            int minY = party == m ? INT_MAX : nums2[party];
            
            if(maxX <= minY && maxY <= minX){
                if((n+m)%2==0){
                    return (1.0*(max(maxX,maxY)+min(minX,minY)))/2.0;
                }
                else{
                    return max(maxX,maxY)*1.0;
                }
            }
            
            if(maxX > minY){
                h=partx - 1;
            }
            else{
                l=partx + 1;
            }
        }
        
        return 1.0;
    }
};