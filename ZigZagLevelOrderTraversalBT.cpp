/*

Given a binary tree, return the zigzag level order traversal of its nodes’ values. 
(ie, from left to right, then right to left for the next level and alternate between).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
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

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    vector<int> temp;
    bool LefttoRight = true;
    stack<TreeNode*> currLevel,nextLevel;
    if(!A)
        return ans;
    currLevel.push(A);
    int i=0;
    while(!currLevel.empty()){
        TreeNode *node = currLevel.top();
        currLevel.pop();
        if(node)
            temp.push_back(node->val);
        if(LefttoRight){
            if(node->left)
                nextLevel.push(node->left);
            if(node->right)
                nextLevel.push(node->right);
        }
        else{
            if(node->right)
                nextLevel.push(node->right);
            if(node->left)
                nextLevel.push(node->left);
        }
        if(currLevel.empty()){
            LefttoRight = !LefttoRight;
            ans.push_back(temp);
            swap(currLevel,nextLevel);
            temp.clear();
        }
    }
    return ans;
}
