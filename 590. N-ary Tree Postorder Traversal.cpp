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
    vector<int> postorder(Node* root) {
        if(!root)
            return {};
        stack<Node *>st;
        vector<int> res;
        st.push(root);
        while(!st.empty()){
            Node *node = st.top();
            st.pop();
            res.push_back(node->val);
            for(auto ch:node->children)
                st.push(ch);
        }
        reverse(res.begin(),res.end());
        
        return res;
    }
};
