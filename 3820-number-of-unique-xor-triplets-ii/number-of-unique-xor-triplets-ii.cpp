class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>pairs;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                pairs.insert(nums[i]^nums[j]);
            }
        }

        unordered_set<int>result;
        for(int x:pairs){
            for(int i=0;i<n;i++){
                result.insert(x^nums[i]);
            }
        }
        return result.size();
    }
};