class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int cnt = 0;
        int st = 0;
        int maxele = *max_element(nums.begin(), nums.end());
        for (int e = 0; e < nums.size(); e++) {
            if (nums[e] == maxele) {
                cnt++;
            }
            if (cnt >= k) {
                ans += (nums.size() - e);
                // st++;

                while (st < e && st < nums.size() && nums[st] != maxele) {
                    ans+=nums.size()-e;
                    st++;
                }
                st++;
                // ans++;
                cnt--;
            }
        }
        return ans;
    }
};