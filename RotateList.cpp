/*
https://www.interviewbit.com/problems/rotate-list/

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int k) {
    if(A==NULL)
        return A;
    int len=0;
    ListNode *curr = A;
    ListNode *temp = curr;
    while(curr!=NULL){
        len++;
        curr=curr->next;
    }
    if(k%len==0)
        return A;
    curr=A;
    
    for(int i=0;i<len-k%len-1;i++){
        //prev = temp;
        temp=temp->next;
    }
    ListNode *ahead = temp->next;
    temp->next=NULL;
    ListNode *last = ahead;
    while(last->next!=NULL){ 
        last=last->next;
    }
    last->next=A;
    A=ahead;
    return A;
}
