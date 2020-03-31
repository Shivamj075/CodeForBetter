/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>>res;
        while(!q.empty()){
            Node *node = q.front();
            vector<int> tmp;
            q.pop();
            if(node){
                while(node!=NULL){
                    tmp.push_back(node->val);
                    for(auto neigh:node->children)
                        q.push(neigh);
                    node = q.front();
                    q.pop();
                }
                res.push_back(tmp);
                q.push(NULL);
            }
        }
        
        return res;
    }
};
