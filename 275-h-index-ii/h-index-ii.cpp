class Solution {
public:
    int hIndex(vector<int>& citations) {
       int low=0;
       int high=citations.size()-1;

       while(low<=high){
        int mid=low+(high-low)/2;
        int h=citations.size()-mid;
        if(citations[mid]>=h){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       } 
       return citations.size()-low;
    }
};