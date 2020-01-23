/*
struct ListNode {
    int val;
    ListNode *right,*down;
    ListNode(int x) {
        val = x;
        right = down = NULL;
    }
};
*/
ListNode *merge(ListNode *root1,ListNode *root2){
    if(root1==NULL)
        return root2;
    if(root2==NULL)
        return root1;
    ListNode *result;
    if(root1->val<root2->val){
        result = root1;
        result->down = merge(root1->down,root2);
    }
    else{
        result = root2;
        result->down =  merge(root1,root2->down);
    }
    
    return result;
}
ListNode* flatten (ListNode* root) {
    if(root==NULL)
        return root;
    // root->right = flatten(root->right);
    // root = merge(root->right);
    
    return merge(root,flatten(root->right));

}
