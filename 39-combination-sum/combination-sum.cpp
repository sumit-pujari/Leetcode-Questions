class Solution {
public:
    
    void solve(vector<int> &candidate,int n,int idx,vector<int>& diary,int sum,int target,vector<vector<int>>& ans){
        if(sum==target){
            ans.push_back(diary);
            return;
        }
        if(idx==n){
            return;
        }

        //choice 1  not take
        solve(candidate,n,idx+1,diary,sum,target,ans);
        if(candidate[idx]+sum<=target){
            diary.push_back(candidate[idx]);
            sum+=candidate[idx];
            solve(candidate,n,idx,diary,sum,target,ans);  //to take same idx
            diary.pop_back();
            sum-=candidate[idx];
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int n=candidates.size();
        int idx=0;
        int sum=0;
        vector<int>diary;
        solve(candidates,n,idx,diary,sum,target,ans);
        return ans;
    }
};