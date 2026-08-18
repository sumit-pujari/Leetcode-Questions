class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int>f1;
        unordered_map<char,int>f2;

        for(int i=0;i<s.size();i++){
            f1[s[i]]++;
        }

        for(int i=0;i<target.size();i++){
            f2[target[i]]++;
        }

        int ans=INT_MAX;
        for(auto i:f2){
            char ch=i.first;
            int need=i.second;
            int have=f1[ch];
            ans=min(ans,have/need);
        }
        return ans;
    }
};