class Solution {
public:
    string smallestSubsequence(string s) {
        //  unordered_map<char,int>f(26,0);
        //  unordered_map<char,bool>visited(26,false);
         unordered_map<char, int> f;
unordered_map<char, bool> visited;

for (char c = 'a'; c <= 'z'; c++) {
    f[c-'a'] = 0;
    visited[c-'a'] = false;
}
         stack<char>st;
         for(int i=0;i<s.size();i++){
            f[s[i]-'a']++;
         }

         for(int i=0;i<s.size();i++){
            f[s[i]-'a']--;
            if(visited[s[i]-'a']){
                continue;
            }
            while(!st.empty() && st.top()>s[i] && f[st.top()-'a']>0){
                visited[st.top()-'a']=false;
                st.pop();
            }


   
            st.push(s[i]);
            visited[s[i]-'a']=true;
         }

         string ans="";
         while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
         }

      

         reverse(ans.begin(),ans.end());
         return ans;

    }
};