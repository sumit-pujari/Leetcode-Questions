class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minval=*min_element(nums.begin(),nums.end());
        int maxval=*max_element(nums.begin(),nums.end());

        int minidx=0;
        int maxidx=0;

        for(int i=0;i<n;i++){
            if(nums[i]==minval){
                minidx=i;
            }
            else if(nums[i]==maxval){
                maxidx=i;
            }
        }

        int d1=max(minidx,maxidx)+1;
        int d2=max((n-minidx),(n-maxidx));
        int d3=(n-minidx)+maxidx+1;
        int d4=(n-maxidx)+minidx+1;
        

        return min({d1,d2,d3,d4});
    }
};