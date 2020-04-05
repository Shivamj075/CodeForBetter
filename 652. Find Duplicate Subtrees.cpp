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
    vector<TreeNode *> res;
    unordered_map<string,int> um;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       if(!root)
           return {};
        um.clear();
        res.clear();
        dfs(root);
        return res;
    }
    
    string dfs(TreeNode *root){
        if(!root)
            return "";
        string s = to_string(root->val)+","+dfs(root->left)+","+dfs(root->right);
        um[s]++;
        if(um[s]==2)
            res.push_back(root);
        return s;
    }
    
};
