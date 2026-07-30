class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(i/8+1);
        }
        return ans;
    }
};

//x y c d e f g h i j
//0 1 2 3 4 5 6 7 8 9
//1 1 1 1 1 1 1 1 2 2
//ans=12;

// a b c d e
// 0 1 2 3 4
// 1 1 1 1 1
//ans=5;