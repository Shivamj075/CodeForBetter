/*
https://www.interviewbit.com/problems/palindrome-list/

Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

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
 void print(ListNode *A){
     ListNode *curr=A;
     while(curr!=NULL){
         cout<<curr->val<<" ";
         curr=curr->next;
     }
     cout<<endl;
 }
int Solution::lPalin(ListNode* A) {
    ListNode *curr=A;
   // vector<int> elem;
   int len=FindLen(A);
   int mid;
   if(len&1)
    mid = (len+1)/2;
   else
    mid=len/2;
    
    ListNode *midNode = A;
    ListNode *prev;
    for(int i=0;i<mid;i++){
        prev=midNode;
        midNode=midNode->next;
    }
    prev->next=NULL;
    ListNode *curr1 = midNode;
    ListNode *next=NULL;
    prev=NULL;
    //Reverse LinkedList
    while(curr1!=NULL){
        next=curr1->next;
        curr1->next=prev;
        prev=curr1;
        curr1=next;
    }
    //Check Palindrome
    ListNode *s1=A;
    ListNode *s2=prev;
    while(s2!=NULL and s1!=NULL){
        if(s1->val!=s2->val)
         return 0;
        s1=s1->next;
        s2=s2->next;
    }
    
    return 1;
}
