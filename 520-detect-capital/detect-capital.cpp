class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int uppercase=0;
        for(int i=0;i<n;i++){
            if(word[i]>='A' && word[i]<='Z'){
                uppercase++;
            }
        }
        if(uppercase==word.size()){
            return true;
        }
        if(uppercase==0) return true;
        if(uppercase==1 && word[0]>='A' && word[0]<='Z') return true;
        return false;
    }
};