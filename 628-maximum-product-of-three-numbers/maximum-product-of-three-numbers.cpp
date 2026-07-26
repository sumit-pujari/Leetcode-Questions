class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int product1=INT_MAX;
        int product2=INT_MAX;
        for(int i=0;i<n;i++){
            product1=nums[n-1]*nums[n-2]*nums[n-3];
            product2=nums[n-1]*nums[0]*nums[1];  
        }
        int ans=max(product1,product2);
        return ans;
    }
};