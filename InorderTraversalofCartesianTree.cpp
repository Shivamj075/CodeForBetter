/*

Given an inorder traversal of a cartesian tree, construct the tree.

 Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1
      
      
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
 int findMax(vector<int> &A,int start,int end){
     int maxi=start;
     for(int i=start+1;i<=end;i++){
         if(A[i]>A[maxi]){
             maxi=i;
         }
     }
     return maxi;
 }
 
TreeNode *makeTree(vector<int> &A,int start,int end){
    if(start>end)
        return NULL;
    int maxi = findMax(A,start,end);
    TreeNode *node = new TreeNode(A[maxi]);
    node->left = makeTree(A,start,maxi-1);
    node->right = makeTree(A,maxi+1,end);
    
    return node;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    
    return makeTree(A,0,A.size()-1);
}
