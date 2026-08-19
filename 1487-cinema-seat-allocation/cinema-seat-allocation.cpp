class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int totalpeople=n*2;

        unordered_map<int,vector<int>>f;
        for(int i=0;i<reservedSeats.size();i++){
            f[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }

        for(auto x:f){
            bool left=true;
            bool middle=true;
            bool right=true;

            for(int seat:x.second){
                if(seat>=2 && seat<=5){
                    left=false;
                }
                if(seat>=4 && seat<=7){
                    middle=false;
                }
                if(seat>=6 && seat<=9){
                    right=false;
                }
            }
            if(left && right){ }  //2 family
            else if(left || middle || right){
                totalpeople-=1;
            }
            else{
                totalpeople-=2;
            }
        }
        return totalpeople;
    }
};