class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        int n=nums.size();
        int ans=-1;

        //k==1   max element in  array with freq 1
        if(k==1){
            unordered_map<int,int>f;
            for(int i=0;i<n;i++){
                f[nums[i]]++;
            }

            for(int i=0;i<n;i++){
                if(f[nums[i]]==1){
                    ans=max(ans,nums[i]);
                }
            }
            return ans;
        }

        unordered_map<int,int>count;
        for(int start=0;start<=n-k;start++){
            unordered_set<int>st;
            for(int i=start;i<start+k;i++){
                st.insert(nums[i]);
            }
            for(auto x:st){
                count[x]++;
            }
        }
        for(auto x:count){
            if(x.second==1){
                ans=max(ans,x.first);
            }
        }
        return ans;
    }
};