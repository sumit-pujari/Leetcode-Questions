class Solution {
public:
    long long hour(vector<int> &piles, int speed) {
    long long h = 0;
    for (int i = 0; i < piles.size(); i++) {
        h += (piles[i] + speed - 1LL) / speed;
    }
    return h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(), piles.end());
        int ans=high;
        int mid=low+(high-low)/2;
        while(low<=high){
            long long hours=hour(piles,mid);
            if(hours>h){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
            mid=low+(high-low)/2;
        }
        return ans;
    }
};