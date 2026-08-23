class Solution {
public:
    bool sumGame(string nums) {
        int n=nums.size();
        int mid=n/2;
        int sum1=0;
        int sum2=0;
        int q1=0;
        int q2=0;

        //first half
        for(int i=0;i<mid;i++){
            if(nums[i]=='?'){
                q1++;
            }
            else{
                sum1+=nums[i]-'0';
            }
        }

        //second half
        for(int i=mid;i<n;i++){
            if(nums[i]=='?'){
                q2++;
            }
            else{
                sum2+=nums[i]-'0';
            }
        }

        int diff=sum1-sum2;
        int que=q1-q2;

        if(que%2 !=0){
            return true;
        }

        int require=-que*9/2;

        return diff!=require;
    }
};