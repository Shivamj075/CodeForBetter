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
    pair<int,int> p;
    int findBottomLeftValue(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left and !root->right)
            return root->val;
        int lvl=0;
        p = {0,0};
        dfs(root,lvl,0);
        
        return p.first;
    }
    void dfs(TreeNode *root,int lvl,bool flag){
        if(!root)
            return;
        if(!root->left and !root->right){
            if(lvl>p.second)
                p = {root->val,lvl};
            return;
        }
        dfs(root->left,lvl+1,1);
        dfs(root->right,lvl+1,0);
        
    }
};
