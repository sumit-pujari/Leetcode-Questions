class Solution {
public:

    bool isPallindrom(string &str) {
        int i = 0;
        int j = str.size() - 1;

        while (i <= j) {
            if (str[i] != str[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    void solve(string &s, int start,vector<string>& path,vector<vector<string>>& ans) {

        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {

            string check = s.substr(start, end - start + 1);

            if (isPallindrom(check)) {

                // Choose
                path.push_back(check);

                // Explore
                solve(s, end + 1, path, ans);

                // Undo choice
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(s, 0, path, ans);

        return ans;
    }
};