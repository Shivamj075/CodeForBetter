/*
https://www.interviewbit.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int FindLen(ListNode *A){
     int len=0;
     while(A->next!=NULL){
         len++;
         A=A->next;
     }
     return len;
 }
 
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    ListNode *curr1=A;
    ListNode *curr2=B;
    ListNode *node=NULL;
    if(curr1->val<=curr2->val){
        node=curr1;
        curr1=curr1->next;
        node->next=NULL;
    }
    else{
        node=curr2;
         curr2=curr2->next;
        node->next=NULL;
    }
    ListNode *temp=node;
    while(curr1!=NULL&&curr2!=NULL){
        
        if(curr1->val<=curr2->val){
            temp->next=curr1;
            curr1=curr1->next;
            temp=temp->next;
            temp->next=NULL;
        }
        else{
            temp->next=curr2;
            curr2=curr2->next;
            temp=temp->next;
            temp->next=NULL;
        }
    }
    if(curr1==NULL&&curr2!=NULL){
        temp->next=curr2;
        return node;
    }
    else if(curr1!=NULL&&curr2==NULL){
        temp->next=curr1;
        return node;
    }
    else
     return node;
}
