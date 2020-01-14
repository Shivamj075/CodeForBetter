/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<TreeNode *> s1,s2;
    s1.push(A);
    while(!s1.empty()){
        TreeNode *node = s1.top();
        s1.pop();
        s2.push(node);
        if(node->left)
            s1.push(node->left);
        if(node->right)
            s1.push(node->right);
    }
    vector<int> ans;
    while(!s2.empty()){
        ans.push_back(s2.top()->val);
        s2.pop();
    }
    return ans;
}
