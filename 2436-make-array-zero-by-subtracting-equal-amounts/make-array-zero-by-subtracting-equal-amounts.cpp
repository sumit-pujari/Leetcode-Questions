class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int>st;

        for(int x:nums){
            if(x>0){
                st.insert(x);
            }
        }
        return st.size();
    }
};