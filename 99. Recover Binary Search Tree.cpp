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
    TreeNode *first = NULL,*second=NULL;
    TreeNode *prev= new TreeNode(INT_MIN);
public:
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        swap(first->val,second->val);
    }
    
    void inorder(TreeNode *root){
        if(!root)
            return;
        inorder(root->left);
        if(first==NULL and prev->val>root->val)
            first = prev;
        if(first!=NULL and prev->val>root->val)
            second = root;
        prev = root;
        inorder(root->right);
    }
};
