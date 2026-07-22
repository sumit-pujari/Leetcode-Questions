class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>f1;
        unordered_map<char,int>f2;

        for(int i=0;i<ransomNote.size();i++){
            f1[ransomNote[i]]++;
        }

        for(int i=0;i<magazine.size();i++){
            f2[magazine[i]]++;
        }

        

        for(auto i:f1){
            char c=i.first;
            int need=i.second;
            int have=f2[c];

            if(have<need){
                return false;
            }
        }
        return true;
    }
};