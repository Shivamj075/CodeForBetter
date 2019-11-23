void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> rows(A.size(),1);
    vector<int> cols(A[0].size(),1);
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j]==0){
                rows[i]=0;
                cols[j]=0;
            }
        }
    }
    for(int i=0;i<A.size();i++){
        if(rows[i]==0){
            for(int j=0;j<A[0].size();j++)
                A[i][j]=0;
        }
    }
    for(int i=0;i<A[0].size();i++){
        if(cols[i]==0){
            for(int j=0;j<A.size();j++){
                A[j][i]=0;
            }
        }
    }
}
