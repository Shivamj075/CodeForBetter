/*

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of 
 every node never differ by more than 1. 
 
Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3
   
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
 TreeNode *build(const vector<int> &A,int start,int end){
     if(start>end)
        return NULL;
     int mid = (start+end)/2;
     TreeNode *node = new TreeNode(A[mid]);
     node->left = build(A,start,mid-1);
     node->right = build(A,mid+1,end);
     
     return node;
 }
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    
    return build(A,0,A.size()-1);
}
