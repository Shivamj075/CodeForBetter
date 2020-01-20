/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void build(TreeNode *root){
    
}
// TreeNode* Solution::flatten(TreeNode* root) {
//     // O(N) and O(Log(N)) space
//     if(root==NULL)
//         return NULL;
//     stack<TreeNode*> st;
//     TreeNode *A = root;
//     while(root){
//         if(root->right)
//             st.push(root->right);
//         root->right = root->left;
//         root->left = NULL;
//         if(root->right==NULL and !st.empty()){
//             root->right = st.top();
//             st.pop();
//         }
//         root=root->right;
//     }
//     return A;
// }
TreeNode* Solution::flatten(TreeNode* root) {
    // O(N) and O(1) space
    if(root==NULL)
        return NULL;
    TreeNode *A = root;
    while(root){
        if(root->left){
            TreeNode *rightSubtree = root->left;
            while(rightSubtree->right)
                rightSubtree = rightSubtree->right;
            
            rightSubtree->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
    return A;
}
