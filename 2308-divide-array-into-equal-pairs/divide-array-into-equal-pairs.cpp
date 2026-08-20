class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>f;
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
        }

        for(auto x:f){
            if(x.second%2!=0){
                return false;
            }
        }
        return true;
    }
};