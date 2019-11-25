/*
https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int FindLen(ListNode* A){
     int len=0;
     while(A!=NULL){
         A=A->next;
         len++;
     }
     return len;
 }
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    int len = FindLen(A);
    ListNode *curr=A;
    if(B>len){
        ListNode *node = A->next;
        A=node;
        return A;
    }
    ListNode *temp =A;
    for(int i=0;i<len-B-1;i++){
        temp=temp->next;
    }
    if(len==1 and B==1){
        A=NULL;
        return A;
    }
    ListNode *ahead = temp->next->next;
    if(B!=len)
        temp->next=ahead;
    else{
        ListNode *head=temp->next;
        A=head;
    }
    
    return A;
}
