class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        //1 2 2 4 7 8
        int n=piles.size();
        int ans=0;
        int i=n-2;

        for(int count=0;count<n/3;count++){
            ans+=piles[i];
            i-=2;
        }
        return ans;
    }
};