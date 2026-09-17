class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<pair<int, int>> v;

        int left = 0;
        int sum = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                v.push_back({left, right});
            }
        }

        int ans = n + 1;
        int j = 0;
        int minLen = n + 1;

        for (int i = 0; i < v.size(); i++) {
            while (j < i && v[j].second < v[i].first) {
                minLen = min(minLen, v[j].second - v[j].first + 1);
                j++;
            }

            if (minLen != n + 1) {
                int len = v[i].second - v[i].first + 1;
                ans = min(ans, minLen + len);
            }
        }

        return ans == n + 1 ? -1 : ans;
    }
};