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
    int result=0;

    int height(TreeNode* root){
        if(root==NULL) return 0;
        int left1=height(root->left);
        int right1=height(root->right);
        int sum=left1+right1;
        result=max(result,sum);
        return 1+ max(left1,right1);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return result;
    }
};