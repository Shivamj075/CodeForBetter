/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int prevSum=0,total=0;
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return root;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode *node = q.front();
//             q.pop();
//             total+=node->val;
//             if(node->left)
//                 q.push(node->left);
//             if(node->right)
//                 q.push(node->right);
//         }
//         solve(root,total);
        
//         return root;
        convertBST(root->right);
        total+=root->val;
        root->val = total;
        convertBST(root->left);
        
        return root;
    }
    
//     void solve(TreeNode *root,int total){
//         if(!root)
//             return;
//         solve(root->left,total);
//         int elem = root->val;
//         root->val = total-prevSum;
//         prevSum+=elem;
//         solve(root->right,total);        
        
//     }
};
