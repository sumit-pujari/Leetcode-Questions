class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        stack<char>st;

        char ch=s[0];
        st.push(ch);
        for(int i=1;i<n;i++){
            if(!st.empty() && s[i]=='*'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};