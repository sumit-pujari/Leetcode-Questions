class Solution {
private:
    int smaller(vector<vector<int>>& matrix,int n,int m,int guess){
        int row=n-1;
        int col=0;
        int count=0;
        while(row>=0 && col<m){
            if(matrix[row][col]<=guess){
                count+=row+1;
                col++;   
            }
            else{
                row--;
            }
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row=matrix.size();
        int col=matrix[0].size();
        int low=matrix[0][0];
        int high=matrix[row-1][col-1];
        int result=-1;
        while(low<=high){
            int guess=low+(high-low)/2;
            int ans=smaller(matrix,row,col,guess);
            if(ans<k){
                low=guess+1;
            }
            else{
                result=guess;
                high=guess-1;
            }
        }
        return result;
    }
};