class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int  low=0;
        int high=0;
        unordered_map<char,int>f1;
        unordered_map<char,int>f2;

        for(int i=0;i<s1.size();i++){
            f1[s1[i]]++;
        }

        for(high=0;high<s2.size();high++){
            f2[s2[high]]++;
            if(high-low+1>s1.size()){
                f2[s2[low]]--;
                if(f2[s2[low]]==0) f2.erase(s2[low]);
                low++;
            }
            if(high-low+1==s1.size()){
                if(f1==f2) return true;
            }
        }
        return false;
    }
};