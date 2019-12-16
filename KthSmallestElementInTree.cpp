/*

Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST 
 
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
// int Size(TreeNode *A){
//     if(A==NULL)
//         return 0;
//     if(!A->left and !A->right)
//         return 1;
//     return 1+LeftSize(A->left)+LeftSize(A->right);
// }
// int kthValue(TreeNode *A){
//     if()
// }

void inorder(TreeNode *A,int &pos,int k,int &ans){
    if(!A)
        return;
    inorder(A->left,pos,k,ans);
    pos++;
    if(pos==k){
        ans = A->val;
        return;
    }
    inorder(A->right,pos,k,ans);
}
int Solution::kthsmallest(TreeNode* A, int B) {
   int ans=0,pos=0;
   inorder(A,pos,B,ans);
   return ans;
}
