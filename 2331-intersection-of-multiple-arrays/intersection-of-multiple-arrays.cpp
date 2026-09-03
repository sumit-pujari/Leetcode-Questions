class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int>ans;

        unordered_map<int,int>f;
        for(auto &arr:nums){
            for(int num:arr){
                f[num]++;
            }
        }

        for(auto &it:f){
            if(it.second==nums.size()){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};