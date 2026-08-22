class Solution {
public:

    bool isPossible(vector<int>& nums,int k,int mid){
        int sum=0;
        int part=1;

        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                part++;
                sum=nums[i];
                if(part>k) return false;
            }
        }
        return true;;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        long long low=*max_element(nums.begin(),nums.end());
        long long high=0;
        
        for(int i=0;i<nums.size();i++){
            high+=nums[i];
        }

        long long ans =-1;

        while(low<=high){
            long long mid=low+(high-low)/2;
            if(isPossible(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};