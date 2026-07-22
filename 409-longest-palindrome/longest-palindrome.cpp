class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;
        for(int i=0;i<s.size();i++){
            f[s[i]]++;
        }
        int result=0;
        bool odd= false;

        for(auto i:f){
            int val=i.second;
            if(val%2==0){
                result+=val;
            }
            else{
                odd=true;
            }
        }
        if(odd==false){
            return result;
        }

        for(auto i:f){
            int val=i.second;
            if(val%2==1){
                result+=val-1;
            }
        }
        return result+1;
    }
};