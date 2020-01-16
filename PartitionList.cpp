/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *before_head = new ListNode(0);
    ListNode *before = before_head;
    ListNode *after_head = new ListNode(0);
    ListNode *after = after_head;
    
    while(A!=NULL){
        if(A->val<B){
            before->next = A;
            before = before->next;
        }
        else{
            after->next = A;
            after = after->next;
        }
        A = A->next;
    }
    
    after->next = NULL;
    before->next = after_head->next;
    
    return before_head->next;
}
