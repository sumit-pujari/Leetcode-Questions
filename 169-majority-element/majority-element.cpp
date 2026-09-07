class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>f;
        int major=0;
        int res=0;

        for(int i=0;i<n;i++){
            f[nums[i]]++;
        }

        for(auto num:f){
            int x=num.first;
            int freq=num.second;
            if(freq>major){
                major=freq;
                res=x;
            }
        }
        return res;
    }
};