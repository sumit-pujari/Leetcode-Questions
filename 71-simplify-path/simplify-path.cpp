class Solution {
public:
    string simplifyPath(string path) {
        string temp="";
        stack<string>st;
        for(int i=0;i<=path.size();i++){
            if(path[i]=='/'|| i==path.size()){
                if(temp=="" || temp=="."){
                    temp="";
                }
                else if(temp==".."){
                    if(!st.empty()){
                        st.pop();
                    }
                    temp="";
                }
                else{
                    st.push(temp);
                    temp="";
                }
            }
            else{
                temp+=path[i];
            }
        }
        string ans="";
        while(!st.empty()) {
            ans = "/"+st.top()+ans;
            st.pop();
        }
        if(ans == "")
            return "/";
        return ans;
    }
};