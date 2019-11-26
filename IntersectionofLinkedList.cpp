/*
https://www.interviewbit.com/problems/intersection-of-linked-lists/

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

 Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

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
         len++;
         A=A->next;
     }
     return len;
 }
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode *curr1=A;
    ListNode *curr2=B;
    int len1=FindLen(A);
    int len2=FindLen(B);
    int diff = abs(len1-len2);
    if(len1>len2){
        for(int i=0;i<diff;i++)
            curr1=curr1->next;
    }
    else{
        for(int i=0;i<diff;i++)
            curr2=curr2->next;
    }
    
    while(curr1!=NULL and curr2!=NULL){
        if(curr1==curr2)
            return curr1;
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return NULL;
}
