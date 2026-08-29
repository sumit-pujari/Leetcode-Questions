class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=0;
        
        while(low<high){
            int mid=low+(high-low)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    low=mid+2;
                }
                else{
                    high=mid;
                }
            }
            else{
                if(nums[mid]==nums[mid-1]){
                    low=mid+1;
                }
                else{
                    high=mid;
                }
            }
        }
        return nums[low];
    }
};


// 1 1 2 3 3 4 4 8 8
// 0 1 2 3 4 5 6 7 8