class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int rowidx=row-1;
        int colidx=0;
        while(rowidx>=0 && colidx<col){
            int element=matrix[rowidx][colidx];
            if(element==target){
                return true;
            }
            if(element>target){
                rowidx--;
            }
            else{
                colidx++;
            }
        }
        return false;
    }
};