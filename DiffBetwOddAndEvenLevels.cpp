/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A) {
    queue<TreeNode *> q;
    q.push(A);
    q.push(NULL);
    int level = 1;
    int odd=0,even=0;
    while(!q.empty()){
        TreeNode *temp = q.front();
        if(temp==NULL)
            q.pop();
        if(temp){
            while(q.front()!=NULL){
            TreeNode *node  = q.front();
            q.pop();
            if(level%2!=0){
                odd+=node->val;
            }
            else{
                even+=node->val;
            }
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        q.push(NULL);
        level++;
        }
        
    }
    
    return odd-even;
}
