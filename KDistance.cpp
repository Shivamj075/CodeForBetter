/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int pre(TreeNode *A,int B,vector<int> par){
    if(!A)
        return 0;
    int ans=0;
    for(int i=0;i<par.size();i++){
        if(abs(A->val-par[i])<=B)
            ans++;
    }
    par.push_back(A->val);
    int l =pre(A->left,B,par);
    int r = pre(A->right,B,par);
    ans+=l+r;
    return ans;
}
int Solution::solve(TreeNode* A, int B) {
    vector<int> par;
    return pre(A,B,par);
}
