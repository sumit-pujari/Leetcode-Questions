class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int>st;
        int minx=nums[0];
        int maxx=nums[0];
        for(int i:nums){
            minx=min(minx,i);
            maxx=max(maxx,i);
            st.insert(i);
        }

        vector<int>ans;
        for(int i=minx+1;i<maxx;i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};