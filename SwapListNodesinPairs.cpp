/*
https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(A==NULL)
        return A;
    ListNode *curr = A;
    ListNode *ahead = curr->next;
    if(ahead==NULL)
        return A;
    ListNode *temp = ahead;
    ListNode *prev = NULL;
    ListNode *ans = ahead;
    while(curr!=NULL and ahead!=NULL){
        temp = ahead->next;
        curr->next = temp;
        ahead->next = curr;
        if(prev!=NULL){
            prev->next = ahead;
        }
        prev = curr;
        curr=curr->next;
        if(curr!=NULL)
            ahead = curr->next;
    }
    
    return ans;
}
