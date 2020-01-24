/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
TreeLinkNode *NextRight(TreeLinkNode *q){
    if(!q)
        return NULL;
    TreeLinkNode *temp = q->next;
    while(temp!=NULL){
        if(temp->left)
            return temp->left;
        if(temp->right)
            return temp->right;
        temp = temp->next;
    }
    return NULL;
}
void Solution::connect(TreeLinkNode* curr) {
   // TreeLinkNode *curr=A;
    if(!curr)
        return;
    curr->next = NULL;
    while(curr!=NULL){
        TreeLinkNode *q = curr;
        while(q!=NULL){
            if(q->left){
                if(q->right){
                    q->left->next = q->right;
                }
                else{
                    q->left->next = NextRight(q);
                }
            }
            if(q->right)
                q->right->next = NextRight(q);
            q=q->next;
        }
        if(curr->left)
            curr=curr->left;
        else if(curr->right)
            curr = curr->right;
        else
            curr = curr->next;
    }
}
