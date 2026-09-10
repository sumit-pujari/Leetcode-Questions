class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>f;
        //vector<int>freq;
        int odd=0;
        int even=INT_MAX;

        for(int i=0;i<s.size();i++){
            f[s[i]]++;
        }

        for(auto i:f){
           if(i.second%2==1){
            odd=max(odd,i.second);
           }
           else{
            even=min(even,i.second);
           }
        }
        return odd-even;
    }
};