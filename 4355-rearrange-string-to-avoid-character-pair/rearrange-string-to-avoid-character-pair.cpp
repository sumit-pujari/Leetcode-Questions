class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string a1="";
        string a2="";
        string a3="";
        for(int i=0;i<s.size();i++){
            if(y==s[i]){
                a1+=s[i];
            }
            else if(x==s[i]){
                a2+=s[i];
            }
            else{
                a3+=s[i];
            }
        }
        return a1+a2+a3;
    }
};