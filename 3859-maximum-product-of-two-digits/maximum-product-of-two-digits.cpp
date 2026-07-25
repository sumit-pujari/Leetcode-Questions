class Solution {
public:
    int maxProduct(int n) {
        int result=0;
        string s=to_string(n);
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                int product=(s[i]-'0')*(s[j]-'0');
                result=max(result,product);
            }
        }
        return result;
    }
};