class Solution {
public:

    void solve(int close,int open,int n,string& curr,vector<string>& ans){
        if(open==n && close==n ){
            ans.push_back(curr);
            return;
        }

        //open
        if(open<n){
            curr.push_back('(');
            solve(close,open+1,n,curr,ans);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            solve(close+1,open,n,curr,ans);
            curr.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr="";
        solve(0,0,n,curr,ans);
        return ans;
    }
};