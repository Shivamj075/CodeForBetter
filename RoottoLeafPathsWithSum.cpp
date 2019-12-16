/*

Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]

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
void solve(TreeNode *A,int B,vector<int> arr,vector<vector<int>> &path){
    if(A==NULL)
        return;
        
    if(!A->left and !A->right){
        if(B==A->val){
            arr.push_back(A->val);
            path.push_back(arr);
        }
        return;
    }
    arr.push_back(A->val);
    solve(A->left,B-A->val,arr,path);
    solve(A->right,B-A->val,arr,path);
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> path;
    vector<int> arr;
    solve(A,B,arr,path);
    return path;
}
