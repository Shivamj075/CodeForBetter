/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    queue<TreeNode *> q;
    q.push(A);
    q.push(NULL);
    vector<int> ans;
    while(!q.empty()){
        TreeNode *temp = q.front();
        if(temp){
            ans.push_back(temp->val);
            while(q.front()!=NULL){
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                q.pop();
                temp = q.front();
            }
            q.push(NULL);
        }
        q.pop();
    }
    return ans;
}
