class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";

        for (int i = 0; i < n; i++) {

            // Try to keep prefix equal to target
            int x = target[i] - 'a';

            if (freq[x] > 0) {
                freq[x]--;
                ans += target[i];
            }
            else {
                // Find smallest character > target[i]
                int j = x + 1;

                while (j < 26 && freq[j] == 0) {
                    j++;
                }

                if (j < 26) {
                    string res = ans;
                    res += char('a' + j);
                    freq[j]--;

                    // Fill remaining characters smallest first
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            res += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return res;
                }

                // Cannot make it greater here.
                // Backtrack.
                break;
            }
        }

        // Backtrack through the equal prefix
        for (int i = (int)ans.size() - 1; i >= 0; i--) {

            int x = ans[i] - 'a';
            freq[x]++;

            // Find smallest character greater than target[i]
            int j = x + 1;

            while (j < 26 && freq[j] == 0) {
                j++;
            }

            if (j < 26) {
                string res = ans.substr(0, i);
                res += char('a' + j);
                freq[j]--;

                // Fill suffix in ascending order
                for (int k = 0; k < 26; k++) {
                    while (freq[k] > 0) {
                        res += char('a' + k);
                        freq[k]--;
                    }
                }

                return res;
            }
        }

        return "";
    }
};