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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *node = new TreeNode(val);
        if(!root){
            return node;
        }
        if(root->val<val){
            node->left = root;
            return node;
        }
        
        if(val<root->val)
            root->right =  insertIntoMaxTree(root->right,val);
        return root;
        
    }
};
