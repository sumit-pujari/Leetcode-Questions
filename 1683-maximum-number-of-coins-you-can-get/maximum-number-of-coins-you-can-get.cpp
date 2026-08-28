class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        //1 2 2 4 7 8

        int ans=0;
        while(piles.size()>0){
            piles.erase(piles.begin());

            piles.pop_back();

            ans+=piles.back();

            piles.pop_back();
        }
        return ans;
    }
};