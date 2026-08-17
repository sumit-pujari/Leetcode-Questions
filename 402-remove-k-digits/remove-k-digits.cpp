class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(int i=0;i<num.size();i++){
            if(st.empty()){
                st.push(num[i]);
            }
            else{
                while(!st.empty() && st.top()>num[i] && k>0){
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }          
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        string result="";
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());

        //to handle leading zero
        int i=0;
        while(i<result.size() && result[i]=='0'){
            i++;
        }
        result=result.substr(i);
        if(result=="") return "0";
        return result;
    }
};