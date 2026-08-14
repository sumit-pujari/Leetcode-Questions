class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int v1=nums[0],v2=nums[1],v3=nums[n-1],v4=nums[n-2];
        int p1=v1*v2;
        int p2=v3*v4;
        int diff=p2-p1;
        return diff;
    }
};