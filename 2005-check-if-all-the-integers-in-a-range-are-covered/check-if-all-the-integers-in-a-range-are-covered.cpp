class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        
        for(int i=left;i<=right;i++){
            bool covered=false;

            for(auto &range:ranges){
                int start=range[0];
                int end=range[1];

                if(start<=i && i<=end){
                    covered=true;
                    break;
                }
            }
            if(!covered){
                return false;
            } 
        }
        return true;
    }
};