class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int num=n;
        while(num>0){
            int digit=num%10;
            num=num/10;
            
            sum+=digit;
            product*=digit;
        }
        if(n%(sum+product)==0){
            return true;
        }
        return false;
    }
};