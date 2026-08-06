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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        bool leftright=true;
        q.push(root);

        while(!q.empty()){
            int levelsize=q.size();
            vector<int>temp(levelsize);
            int first=0;
            int last=levelsize-1;
            for(int i=0;i<levelsize;i++){
                TreeNode* t=q.front();
                q.pop();
                if(leftright==true){
                    temp[first]=t->val;
                    first++;
                }
                else{
                    temp[last]=t->val;
                    last--;
                }

                if (t->left)
                    q.push(t->left);

                if (t->right)
                    q.push(t->right);
            }
            ans.push_back(temp);
            leftright = !leftright;
        }
        return ans;
    }
};