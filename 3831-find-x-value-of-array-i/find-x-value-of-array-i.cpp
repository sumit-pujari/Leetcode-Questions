class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> cnt(k, 0);

        for(int num : nums) {
            int x = num % k;
            vector<long long> temp(k, 0);

            temp[x]++;

            for(int r = 0; r < k; r++) {
                int rem = (r * x) % k;
                temp[rem] += cnt[r];
            }

            for(int r = 0; r < k; r++) {
                ans[r] += temp[r];
            }

            cnt = temp;
        }

        return ans;
    }
};