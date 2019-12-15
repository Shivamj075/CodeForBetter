/*

Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

 NOTE : The path has to end on a leaf node. 
Example :

         1
        /
       2
max depth = 2.

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
 int depth(TreeNode *A){
     if(A==NULL)
        return 0;
    if(!A->left and !A->right)
        return 1;
    return max(depth(A->left),depth(A->right))+1;
 }
int Solution::maxDepth(TreeNode* A) {
    
    return depth(A);
}
