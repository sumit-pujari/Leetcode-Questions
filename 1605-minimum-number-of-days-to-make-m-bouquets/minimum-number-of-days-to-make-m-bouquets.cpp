class Solution {
public:
    int bouquets(vector<int>& bloomDay,int day,int k){
        int count=0;
        int flower=0;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                flower++;
                if(flower==k){
                    count++;
                    flower=0;
                }
            }
            else{
                flower=0;
            } 
        }
        return count;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long totalflower = 1LL * m * k;

        if(totalflower>n) return -1;

        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        

        while(low<=high){
            int mid=low+(high-low)/2;
            int count=bouquets(bloomDay,mid,k);
            if(count>=m){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};