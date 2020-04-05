/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    queue<TreeNode*>cbtQue;
    TreeNode *rootNode;
    CBTInserter(TreeNode* root) {
        if(root!=NULL){
            rootNode = root;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                TreeNode *nextNode = q.front();
                q.pop();
                if(!nextNode->right or !nextNode->left)
                    cbtQue.push(nextNode);
                if(nextNode->left)
                    q.push(nextNode->left);
                if(nextNode->right)
                    q.push(nextNode->right);
            }
        }
    }
    
    int insert(int v) {
        TreeNode *node = cbtQue.front();
        if(!node->left){
            node->left = new TreeNode(v);
            cbtQue.push(node->left);
        }
        else{
            node->right = new TreeNode(v);
            cbtQue.push(node->right);
            cbtQue.pop();
        }
        
        return node->val;
    }
    
    TreeNode* get_root() {
        return rootNode;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
