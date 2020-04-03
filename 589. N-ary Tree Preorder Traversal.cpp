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
    /*
    Recursive Method
    vector<int> res;
    vector<int> preorder(Node* root) {
        if(!root)
            return {};
        recur(root);
        return res;
    }
    void recur(Node *root){
        if(!root)
            return;
        res.push_back(root->val);
        for(auto elem:root->children)
            recur(elem);
    }
    */
    vector<int> res;
    vector<int> preorder(Node* root) {
        if(!root)
            return {};
        stack<Node *> st;
        st.push(root);
        while(!st.empty()){
            Node *node = st.top();
            st.pop();
            res.push_back(node->val);
            for(int i=node->children.size()-1;i>=0;i--)
                st.push(node->children[i]);
        }
        return res;
    }
};
