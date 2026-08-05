class Solution {
public:
    
    void solve(string &s,int n,int idx,string & diary,vector<string>&ans){

        unordered_map<char,string>f;
        f['2']="abc";  f['3']="def";   f['4']="ghi";
        f['5']="jkl";  f['6']="mno";   f['7']="pqrs";
        f['8']="tuv";  f['9']="wxyz";

        if(idx==n){
            ans.push_back(diary);
            return;
        }

        string choice=f[s[idx]];
        for(int i=0;i<choice.size();i++){
            diary.push_back(choice[i]);
            solve(s,n,idx+1,diary,ans);
            diary.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int n= digits.size();
        int idx=0;
        string diary="";
        solve(digits,n,idx,diary,ans);
        return ans;
    }
};