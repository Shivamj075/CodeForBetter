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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        
        if(d==1){
            TreeNode*node = new TreeNode(v);
            node->left = root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth=1;
        while(depth<d-1){
            
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode *node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            depth++;
        }
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            TreeNode *tmp = node->left;
            node->left = new TreeNode(v);
            node->left->left = tmp;
            tmp = node->right;
            node->right = new TreeNode(v);
            node->right->right = tmp;
        }
        return root;
     }
};
