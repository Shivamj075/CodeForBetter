/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool path(TreeNode *A,int B,vector<int> &p){
    if(A==NULL)
        return 0;
    p.push_back(A->val);
    if(A->val==B){
        return 1;
    }
    
    if((A->left and path(A->left,B,p)) or (A->right and path(A->right,B,p) ))
        return true;
    p.pop_back();
    return 0;
}
int Solution::lca(TreeNode* A, int B, int C) {
    vector<int> path1,path2;
    if(!path(A,B,path1) or !path(A,C,path2))
        return -1;
    auto it1 = path1.cbegin();
    auto it2 = path2.cbegin();
    int same = -1;
    while (it1 != path1.cend() && it2 != path2.cend())
    {
        if (*it1 != *it2)  
            break;
        else
            same = *it1;
        ++it1; ++it2;
    }
    return same;
}
