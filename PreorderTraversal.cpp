/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode *> s;
    vector<int> ans;
    s.push(A);
    while(!s.empty()){
        TreeNode *curr = s.top();
        ans.push_back(curr->val);
        s.pop();
        if(curr->right)
            s.push(curr->right);
        if(curr->left)
            s.push(curr->left);
    }
    return ans;
}
