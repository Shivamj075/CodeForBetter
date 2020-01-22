struct node{
    int frq;
    node *arr[26];
    node(){
        frq=0;
        for(int i=0;i<26;i++)
            arr[i] = NULL;
    }
};

void add(node *root,string s,int idx){
    if(idx==s.size())
        return;
    if(root->arr[s[idx]-'a']==NULL)
        root->arr[s[idx]-'a'] = new node();
    root->arr[s[idx]-'a']->frq++;
    add(root->arr[s[idx]-'a'],s,idx+1);
}
int find(node *root,string s,int idx){
    if(root->arr[s[idx]-'a']->frq==1)
        return idx;
    if(root->arr[s[idx]-'a']!=NULL)
        return find(root->arr[s[idx]-'a'],s,idx+1);
    return -1;
}

vector<string> Solution::prefix(vector<string> &A) {
    
    node *root = new node();
    vector<string> ans;
    for(int i=0;i<A.size();i++)
        add(root,A[i],0);
    for(int i=0;i<A.size();i++){
        int idx = find(root,A[i],0);
        string res="";
        for(auto ch:A[i]){
            if(idx<0)
                break;
            res+=ch;
            idx--;
        }
        ans.push_back(res);
    }
    return ans;
}
