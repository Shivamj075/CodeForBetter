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
    long long sum,ans;
    const int MOD = 1e9+7;
    int maxProduct(TreeNode* root) {
        ans=0,sum=0;
        dfs(root);
        findMax(root);
        
        return ans%MOD;
    }
    void dfs(TreeNode *root){
        if(!root)
            return;
        sum+=root->val;
        dfs(root->left);
        dfs(root->right);
    }
    
    long long findMax(TreeNode *root){
        if(!root)
            return 0;
        long long res = root->val+findMax(root->left)+findMax(root->right);
        ans = max(ans,res*(sum-res));
        return res;
    }
};
