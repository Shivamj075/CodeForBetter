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
    vector<int>res;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        
        int ind=0;
        
        return solve(root,voyage,ind)?res:vector<int>()={-1};
        
    }
    
    bool solve(TreeNode *root,vector<int>&pre,int &ind){
        if(!root)
            return 1;
        if(root->val!=pre[ind++]){
            // res.clear();
            // res.push_back(-1);
            return 0;
        }
        auto l  = root->left;
        auto r =  root->right;
        if(l!=NULL and l->val!=pre[ind]){
            swap(l,r);
            res.push_back(root->val);
        }
        
        return solve(l,pre,ind)and solve(r,pre,ind);
    }
    
};
