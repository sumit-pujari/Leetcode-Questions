class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(st.empty() || st.top().first!=ch){
                st.push({ch,1});
            }
            else{
                st.top().second++;
                if(st.top().second==k){
                    st.pop();
                }
            }
            
        }
        string ans="";
        while(!st.empty()){
            char ch=st.top().first;
            int count=st.top().second;
            while(count--){
                ans+=ch;
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};