/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void Path(TreeNode* root,int sum,int targetSum,vector<int>& ans,vector<vector<int>>& result){
        if(root==NULL) return;
        sum+=root->val;
        ans.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                result.push_back(ans);
                ans.pop_back();
                return;
            }
        }
        Path(root->left,sum,targetSum,ans,result);
        Path(root->right,sum,targetSum,ans,result);
        ans.pop_back();   //for nonleaf;
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ans;
        vector<vector<int>>result;
        Path(root,0,targetSum,ans,result);
        return result;
    }
};