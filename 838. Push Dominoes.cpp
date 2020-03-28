class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n=dominoes.size();
        vector<int>index(n+2);
        vector<char> symbols(n+2);
        int len=1;
        index[0] = 0;
        symbols[0] = 'L';
        for(int i=0;i<n;i++){
            if(dominoes[i]!='.'){
                index[len] = i;
                symbols[len++] = dominoes[i];
            }
        }
        
        index[len]  = n;
        symbols[len++]= 'R';
        
        string ans = dominoes;
        for(int ind=0;ind<len-1;++ind){
            int i=index[ind],j=index[ind+1];
            char x = symbols[ind],y=symbols[ind+1];
            if(x==y){
                for(int k=i;k<j;k++)
                    ans[k] = x;
            }
            else if(x>y){
                for(int k=i+1;k<j;k++){
                    ans[k] = k-i==j-k?'.':k-i<j-k?'R':'L';
                }
            }
        }
        if(dominoes.size()>=2 and dominoes[0]=='.' and dominoes[1]=='L')
            ans[0] ='L';
        
        return ans;
    }
};
