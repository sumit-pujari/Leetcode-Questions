class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int low=0;
        int high=0;
        int ans=0;
        unordered_map<int,int>f;

        for(high=0;high<n;high++){
            f[s[high]]++;
            while(f[s[high]]>2){
                f[s[low]]--;
                low++;
            }
            int len=high-low+1;
            ans=max(ans,len);
        }
        return ans;
    }
};