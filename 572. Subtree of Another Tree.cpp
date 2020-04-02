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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return traverse(s,t);
    }
    
    bool isIdentical(TreeNode *s,TreeNode *t){
        if(!s and !t)
            return 1;
        if(s==NULL or t==NULL)
            return 0;
        return s->val==t->val and isIdentical(s->left,t->left) and isIdentical(s->right,t->right);
    }
    
    bool traverse(TreeNode *s,TreeNode *t){
        
        return s!=NULL and (isIdentical(s,t) or traverse(s->left,t) or traverse(s->right,t));
    }
};
