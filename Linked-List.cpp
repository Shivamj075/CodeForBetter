#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
};
ListNode *A = NULL;
void insert_node(int position, int value) {
    // @params position, integer
    // @params value, integer
    ListNode *newNode = new ListNode();
    newNode->val = value;
    newNode->next = NULL;
    ListNode *temp = A;
    if(A==NULL){
        A = newNode;
    }
    else if(position==1){
        A = newNode;
        A->next = temp;
    }
    else{
        for(int i=0;i<position-2;i++){
            temp=temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void delete_node(int position) {
    // @params position, integer
    
    if (A == NULL) 
      return; 
  
   struct ListNode* temp = A; 
  
    if (position == 1) 
    { 
        A = temp->next;  
        free(temp);         
        return; 
    } 
  
    for (int i=0; temp!=NULL && i<position-2; i++) 
         temp = temp->next; 
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    struct ListNode *next = temp->next->next; 
  
    free(temp->next); 
  
    temp->next = next;  
}


void print_ll() {
    // Output each element followed by a space
    ListNode *temp = A;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
   // cout<<endl;
}
