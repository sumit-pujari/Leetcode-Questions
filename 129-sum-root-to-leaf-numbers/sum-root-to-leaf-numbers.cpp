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

    void Sum(TreeNode* root ,int sum,int& result){
        if(root==NULL) return;

        sum=sum*10+root->val;

        if(root->left==NULL && root->right==NULL){
            result+=sum;
            return;
        }

        Sum(root->left,sum,result);
        Sum(root->right,sum,result);
        return;
    }

    int sumNumbers(TreeNode* root) {
        int result=0;
        Sum(root,0,result); 
        return result;
    }
};