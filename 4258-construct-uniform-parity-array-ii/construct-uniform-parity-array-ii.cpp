class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int>nums2;

        int minval=*min_element(nums1.begin(),nums1.end());

        if(minval%2==1){
            return true;
        }

        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==1 && nums1[i]>minval){
                return false;
            }
        }
        return true;
    }
};