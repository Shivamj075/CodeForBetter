/*

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along 
the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

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
bool chk(TreeNode *A,int B,int s){
    if(A==NULL){
        return 0;
    }
    s+=A->val;
    if(!A->left and !A->right)
        return s==B;
    return chk(A->left,B,s) or chk(A->right,B,s);
}
int Solution::hasPathSum(TreeNode* A, int B) {
    int s=0;
    if(chk(A,B,s))
        return 1;
    return 0;
}
