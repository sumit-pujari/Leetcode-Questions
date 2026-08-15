class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int result=0;
        unordered_map<int,int>f;
        f[0]=-1;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                sum--;
            }
            else{
                sum++;
            }
            if(f.find(sum)!=f.end()){
                result=max(result,i-f[sum]);
            }
            else{
                f[sum]=i;
            }
        }
        return result;
    }
};