class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string>st;

        for(int i=0;i<s.size()-1;i++){
            st.insert(s.substr(i,2));
        }

        for(int i=0;i<s.size()-1;i++){
            string sub=s.substr(i,2);
            reverse(sub.begin(),sub.end());

            if(st.find(sub)!=st.end()) return true;
        }
        return false;
    }
};