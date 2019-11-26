/*

https://www.interviewbit.com/problems/reverse-link-list-ii/

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 

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
     while(A!=NULL){
         A=A->next;
         len++;
     }
     return len;
 }
 void print(ListNode *A){
     while(A!=NULL){
         cout<<A->val<<" ";
         A=A->next;
     }
     cout<<endl;
 }
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode *curr=A,*first=A,*second=A;
    ListNode *prev=NULL,*prev1=NULL;
    int len=FindLen(A);
    if(len==1)
        return A;
    for(int i=0;i<B-1;i++){
        prev=first;
        first=first->next;
    }
    //print(first);
    for(int i=0;i<C;i++){
        prev1=second;
        second=second->next;
    }
    //print(prev1);
    ListNode *next;
    for(int i=B-1;i<C;i++){
        next = first->next;
        first->next=second;
        second = first;
        first = next;
       // print(A);
    }
    //print(prev);
    if(B>1)
     prev->next = second;
    else
        A=second;
    //print(first);
    return A;
}
