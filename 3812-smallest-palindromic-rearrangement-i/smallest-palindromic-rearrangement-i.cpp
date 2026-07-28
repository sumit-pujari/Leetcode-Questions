class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char, int> f;
        for (char c : s) {
            f[c]++;
        }
        string first = "";
        char mid = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            while (f[c] >= 2) {
                first += c;
                f[c] -= 2;
            }
            if (f[c] == 1)
                mid = c;
        }
        string second = first;
        reverse(second.begin(), second.end());
        if (mid)
            return first+mid+second;

        return first+second;
    }
};