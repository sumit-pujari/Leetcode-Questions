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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int levelsize=q.size();
            long long sum=0;

            vector<int>temp;
            for(int i=0;i<levelsize;i++){
                TreeNode* t=q.front();
                q.pop();

                sum+=t->val;
                
                temp.push_back(t->val);
                if(t->left!=NULL){
                    q.push(t->left);
                }
                if(t->right!=NULL){
                    q.push(t->right);
                }
            }
            double avg=(double)sum/levelsize;
            ans.push_back(avg);
        }
        return ans;
    }
};