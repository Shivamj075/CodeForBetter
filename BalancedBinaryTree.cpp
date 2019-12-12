/*
https://www.interviewbit.com/problems/balanced-binary-tree/
Given a binary tree, determine if it is height-balanced.

 Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by 
 more than 1. 
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
//  int height(TreeNode *A){
//      if(A==NULL)
//         return 0;
//      int lh = height(A->left);
//         if(lh==-1)
//             return -1;
//     int rh = height(A->right);
//         if(rh==-1)
//             return -1;
//     if(abs(rh-lh)>1)
//         return -1;
        
//     return 1+max(lh,rh);
//  }

int depth(TreeNode *root){
        return root ? max(depth(root->left), depth(root->right))+1 : 0;
    }
bool isBalance(TreeNode* root) {
        return root ? (isBalance(root->left) && isBalance(root->right)) ? abs(depth(root->left)-depth(root->right))<=1 : false : true;
    }
    

int Solution::isBalanced(TreeNode* A) {
    if(!isBalance(A))
        return 0;
    return 1;
}
