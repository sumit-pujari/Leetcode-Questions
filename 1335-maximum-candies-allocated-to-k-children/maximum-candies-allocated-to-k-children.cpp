class Solution {
public:
    bool check(vector<int>& candies,long long k,long long x){
        long long children=0;

        for(int i=0;i<candies.size();i++){
            children+=candies[i]/x;
        }
        if(children>=k) {
            return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long low=1;
        long long high=*max_element(candies.begin(),candies.end());
        long long ans=0;

        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(candies,k,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};