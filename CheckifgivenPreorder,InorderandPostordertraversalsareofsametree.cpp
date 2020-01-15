// Definition for binary tree
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };

int search(vector<int> &In,int start,int end,int elem){
    int i;
     for(i=start;i<end;i++){
         if(In[i]==elem)
            return i;
     }
     return i;
 }
void build(vector<int> &pre, vector<int> &In, vector<int> &post,int start,int end,int &preIndex,int &postIndex,bool &res){
    if(start>end)
        return;
        
    int indx = search(In,start,end,pre[preIndex++]);
    
    build(pre,In,post,start,indx-1,preIndex,postIndex,res);
    build(pre,In,post,indx+1,end,preIndex,postIndex,res);
    if(In[indx] != post[postIndex++]) {
       
        res = false;
    }

}
int Solution::solve(vector<int> &pre, vector<int> &In, vector<int> &post) {
    int n = pre.size();
    
    int preIndex = 0; 
    int postIndex = 0;
    bool res = true;
    
    build(pre, In, post, 0,n-1, preIndex, postIndex, res);
    
    return res;
}
