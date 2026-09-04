class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>right(n);
        int maxval=nums[0];

        right[n-1]=nums[n-1];

        //0,0,1,4
        for(int i=n-2;i>=0;i--){
            right[i]=min(nums[i],right[i+1]);
        }

        
        for(int i=0;i<n;i++){
            maxval=max(maxval,nums[i]);

            int stable=maxval-right[i];
            if(stable<=k){
                return i;
            }
        }
        return -1;
    }
};