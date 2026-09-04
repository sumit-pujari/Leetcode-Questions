class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> f;

        for (int i = 0; i < s.size(); i++) {
            f[s[i]]++;

            if (f[s[i]] == 2) {
                return s[i];
            }
        }

        return '\0';
    }
};