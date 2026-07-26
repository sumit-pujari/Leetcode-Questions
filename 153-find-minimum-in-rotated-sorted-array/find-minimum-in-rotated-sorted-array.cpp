class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        //int ans=0;
        int mid=low+(high-low)/2;
        while(low<high){
            if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else{
                high=mid;
            }
            mid=low+(high-low)/2;
        }
        return nums[mid];
    }
};