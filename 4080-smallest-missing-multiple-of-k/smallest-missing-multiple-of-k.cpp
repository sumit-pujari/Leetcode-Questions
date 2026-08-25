class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans=k;
        set<int>st(nums.begin(),nums.end());
        while(st.count(ans)){
            ans+=k;
        }
    return ans;
    }
};