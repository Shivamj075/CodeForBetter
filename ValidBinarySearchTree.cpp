/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isValid(TreeNode *root,int min,int max){
    if(root==NULL)
        return 1;
    if(root->val<=min or root->val>=max)
        return false;
    return isValid(root->left,min,root->val) and isValid(root->right,root->val,max);
}
int Solution::isValidBST(TreeNode* A) {
    
    return isValid(A,INT_MIN,INT_MAX);
}
