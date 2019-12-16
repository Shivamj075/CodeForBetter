/*

Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3


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
 int Search(vector<int>&in,int inStart,int inEnd,int data){
     for(int i=inStart;i<=inEnd;i++){
         if(in[i]==data)
            return i;
     }
     return -1;
 }
 TreeNode *build(vector<int> &pre,vector<int> &in,int inStart,int inEnd,int &pIndex){
     if(inStart>inEnd or pIndex>=pre.size())
        return NULL;
    int data = pre[pIndex++];
    TreeNode *node  = new TreeNode(data);
    
    if(inStart==inEnd)
        return node;
    int index = Search(in,inStart,inEnd,data);
    
    node->left = build(pre,in,inStart,index-1,pIndex);
    node->right = build(pre,in,index+1,inEnd,pIndex);
    
    return node;
 }
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int p = 0;
    return build(A,B,0,B.size()-1,p);
}
