class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>f1;
        unordered_map<char,int>f2;
        int low=0,high=0;
        vector<int>ans;
        
        for(int i=0;i<p.size();i++){
            f1[p[i]]++;
        }

        for(high=0;high<s.size();high++){
            f2[s[high]]++;
            if(high-low+1> p.size()){
                f2[s[low]]--;
                if(f2[s[low]]==0) f2.erase(s[low]);
                low++;
            }
            if(high-low+1==p.size()){
                if(f1==f2){
                    ans.push_back(low);
                }
            }
        }
        return ans;
    }
};