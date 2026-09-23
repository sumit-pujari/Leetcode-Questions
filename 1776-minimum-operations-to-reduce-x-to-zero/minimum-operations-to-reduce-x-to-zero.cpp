class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int total=0;

        for(int num:nums){
            total+=num;
        }

        int target=total-x;
        if(target<0) return -1;
        if(target==0) return n;

        int sum=0;
        int low=0;
        int ops=-1;

        for(int high=0;high<n;high++){
            sum+=nums[high];

            while(sum>target){
                sum-=nums[low];
                low++;
            }

            if(sum==target){
                ops=max(ops,high-low+1);
            }
        }
        if(ops==-1) return -1;
        return n-ops;
    }
};