class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;

        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }

        int leftsum=0;
        vector<int>ans;

        for(int i=0;i<n;i++){
            int rightsum=totalsum-leftsum-nums[i];
            int diff=abs(rightsum-leftsum);
            ans.push_back(diff);
            leftsum+=nums[i];
        }
        return ans;
    }
};



