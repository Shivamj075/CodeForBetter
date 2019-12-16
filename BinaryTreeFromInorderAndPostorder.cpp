/*

Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

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
 int Search(vector<int> &in,int inStart,int inEnd,int data){
     for(int i=inStart;i<=inEnd;i++){
         if(in[i]==data)
            return i;
     }
     return -1;
 }
 TreeNode *build(vector<int> &in,vector<int> &post,int inStart,int inEnd,int &pIndex){
    if (inStart>inEnd)
        return NULL;
    TreeNode* node = new TreeNode(post[pIndex--]);
    if (inStart==inEnd)
        return node;
    int inde = Search(in, inStart, inEnd, node->val);
    node->right = build(in, post, inde+1, inEnd, pIndex);
    node->left = build(in, post, inStart, inde-1, pIndex);
    return node;
 }
 
TreeNode* Solution::buildTree(vector<int> &in, vector<int> &post) {
    int p = post.size()-1;
    return build(in,post,0,in.size()-1,p);
}
