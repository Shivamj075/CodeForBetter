/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // INplace
        if(!t1)
            return t2;
        if(!t2)
            return t1;
        t1->val+=t2->val;
        
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        
        return t1;
    }
    /* outPlace
    TreeNode *solve(TreeNode *t1,TreeNode *t2){
        if(t1 and t2){
            TreeNode *root = new TreeNode(t1->val+t2->val);
            root->left = solve(t1->left,t2->left);
            root->right = solve(t1->right,t2->right);
            
            return root;
        }
        else
            return t1?t1:t2;
    }
    */
    
};
