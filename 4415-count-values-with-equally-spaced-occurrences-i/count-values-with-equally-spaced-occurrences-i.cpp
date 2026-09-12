class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>f;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            f[nums[i]].push_back(i);
        }

        for(auto& [nums,indices]:f){
            if(indices.size()==3){
                if(indices[1]-indices[0]==indices[2]-indices[1]){
                    ans++;
                } 
            }
        }
        return ans;
    }
};