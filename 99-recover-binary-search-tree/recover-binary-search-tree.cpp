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
    int wrong =0;
    TreeNode* prev=NULL;
    TreeNode* w11=NULL;
    TreeNode* w12=NULL;
    TreeNode* w21=NULL;
    TreeNode* w22=NULL;

    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev==NULL) {
            prev=root;
        }
        else{
            if(root->val < prev->val){
                if(wrong==0){
                    w11=prev;
                    w12=root;
                    wrong++;
                }
                else{
                    w21=prev;
                    w22=root;
                    wrong++;
                }
            }
            prev=root;
        }
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        if(wrong==1){
            swap(w11->val,w12->val);
        }
        else{
            swap(w11->val,w22->val);
        }
        return;
    }
};




    // void inorder(TreeNode* root ,vector<int>& order){
    //     if(root==NULL) return;

    //     inorder(root->left,order);
    //     order.push_back(root->val);
    //     inorder(root->right,order); 
    // }


    // void recoverTree(TreeNode* root) {
    //     vector<int>order;
    //     inorder(root,order);
        
    //     int wrong=0;
    //     int w11,w12,w21,w22;     //wrong1dfirst wrong2second.....

    //     for(int i=0;i<order.size()-1;i++){
    //         if(order[i]>order[i+1]){
    //             if(wrong==0){
    //                 w11=order[i];
    //                 w12=order[i+1];
    //                 wrong++;
    //             }
    //             else{
    //                 w21=order[i];
    //                 w22=order[i+1];
    //                 wrong++;
    //             }
    //         }
    //     }

    //     if(wrong==1){
    //         swap(w11,w12);
    //     }
    //     else{
    //         swap(w11,w22);
    //     }
    //     return;
    // }
