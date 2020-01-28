/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct compare{
    bool operator()(ListNode *A,ListNode *B){
        return A->val > B->val;
    }
};

ListNode *merge(ListNode *A,ListNode *B){
    //O(NK logK) O(1) space
    if(A==NULL)
        return B;
    if(B==NULL)
        return A;
    ListNode *result=NULL;
    if(A->val < B->val){
        result = A;
        result->next = merge(A->next,B);
    }
    else{
        result = B;
        result->next = merge(A,B->next);
    }
    
    return result;
}

ListNode *solve(vector<ListNode*> &A){
    //Using MIN heap O(nklogk) O(k) space
    ListNode *head = new ListNode(0);
    ListNode *tail = head;
    priority_queue<ListNode *,vector<ListNode *>,compare> pq;
    for(int i=0;i<A.size();i++){
        if(A[i]!=NULL)
            pq.push(A[i]);
    }
    while(!pq.empty()){
        tail->next = pq.top();
        pq.pop();
        
        tail = tail->next;
        if(tail->next)
            pq.push(tail->next);
    }
    return head->next;
}
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode *root = A[0];
    for(int i=1;i<A.size();i++){
        root = merge(root,A[i]);
    }
    return root;
    
    
}
