class Solution {
public:
    int first(vector<int>& nums,int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid=low+(high-low)/2;
        int ans=-1;
        while(low<=high){
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            mid=low+(high-low)/2;
        }
        return ans;
    }


    int last(vector<int>& nums,int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid=low+(high-low)/2;
        int ans=-1;
        while(low<=high){
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            mid=low+(high-low)/2;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPlace=first(nums,target);
        int lastPlace=last(nums,target);
        return {firstPlace,lastPlace};
    }
};