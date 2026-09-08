class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j=0;
        string ans="";
        for(int i=0;i<spaces.size();i++){
            while(j<spaces[i]){
                ans.push_back(s[j]);
                j++;
            }
            ans.push_back(' ');
        }

        while(j<s.size()){
            ans.push_back(s[j]);
            j++;
        }
        return ans;
    }
};