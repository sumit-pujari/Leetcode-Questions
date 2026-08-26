class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        unordered_map<int,int>f;
        int low=0;
        //int high=0;
        int n=s.size();
        string ans="";
        int ones=0;

        for(int high=0;high<n;high++){
           if(s[high]=='1'){
            ones++;
           }
           while(ones>k){
            if(s[low]=='1'){
                ones--;
                }
                low++;
            }

            while(low<=high && s[low]=='0'){
                low++;
            }
            if(ones==k){
                string temp=s.substr(low,high-low+1);

                if(ans=="" || temp.size()< ans.size()){
                    ans=temp;
                }

                else if(ans.size()==temp.size() && temp<ans){
                    ans=temp;
                }
            }
        }
        return ans;
    }
};