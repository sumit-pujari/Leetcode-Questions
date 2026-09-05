class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++){
            unordered_map<char,int>f;
            for(int j=i;j<n;j++){
                f[s[j]]++;

                int count=-1;
                bool balance=true;
                for(auto &i : f){
                    if(count==-1){
                        count=i.second;
                    }
                    else if(count!=i.second){
                        balance=false;
                        break;
                    }
                }
                if(balance){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};