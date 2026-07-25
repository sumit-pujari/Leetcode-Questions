class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int mid=low+(high-low)/2;
        while(low<high){
            if(arr[mid]<arr[mid+1]){
                low=mid+1;
            }
            else{
                high=mid;
            }
            mid=low+(high-low)/2;
        }
        return mid;
    }
};