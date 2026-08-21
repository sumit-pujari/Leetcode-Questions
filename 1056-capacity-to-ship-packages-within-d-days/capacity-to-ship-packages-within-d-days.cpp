class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0;
        int high=0;
        int n=weights.size();

        for(int i=0;i<n;i++){
            low=max(low,weights[i]);
            high+=weights[i];
        }

        while(low<=high){
            int mid=low+(high-low)/2;
            int day=1;
            int sum=0;
            for(int i=0;i<n;i++){
                if(sum+weights[i]<=mid){
                    sum+=weights[i];
                }
                else{
                    day++;
                    sum=weights[i];
                }
            }
            if(day<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};