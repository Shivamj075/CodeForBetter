/*
https://www.interviewbit.com/problems/inorder-traversal/

Given a binary tree, return the inorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

Using recursion is not allowed.

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// void inorder(TreeNode *A,vector<int> &ans){ //Using Recursion
//     if(A==NULL)
//         return;
//     inorder(A->left,ans);
//     ans.push_back(A->val);
//     inorder(A->right,ans);
// }
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode *curr = A;
    while(curr!=NULL or s.empty()==false){
        
        while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
            }
        curr = s.top();
        s.pop();
        ans.push_back(curr->val);
        curr = curr->right;
    }
    return ans;
}
