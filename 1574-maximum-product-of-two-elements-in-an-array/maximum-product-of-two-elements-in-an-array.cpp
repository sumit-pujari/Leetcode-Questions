class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int p1=nums[n-1]-1;
        int p2=nums[n-2]-1;
        return p1*p2;
    }
};