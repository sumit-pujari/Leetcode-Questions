class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        int n=nums.size();
        int low=0;
        int high=0;
        int result=-1;
        for(high=0;high<n;high++){
            f[nums[high]]++;
            while(f[nums[high]]>k){
                f[nums[low]]--;
                if(f[nums[low]]==0) {
                    f.erase(nums[low]);
                }
                low++;
            }
            int length=high-low+1;
            result=max(result,length);
        }
        return result;
    }
};