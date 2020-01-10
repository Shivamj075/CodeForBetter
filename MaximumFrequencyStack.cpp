vector<int> Solution::solve(vector<vector<int> > &A) {
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> freqelem;
    int maxfreq = 0;
    vector<int> ans;
    for(int i=0;i<A.size();i++){
        if(A[i][0]==1){
            int freqofelem = ++freq[A[i][1]];
            freqelem[freqofelem].push(A[i][1]);
            maxfreq = max(maxfreq,freqofelem);
            ans.push_back(-1);
        }
        else{
            int elem = freqelem[maxfreq].top();
            freqelem[maxfreq].pop();
            freq[elem]--;
            ans.push_back(elem);
            if(freqelem[maxfreq].empty())
                maxfreq--;
        }
    }
    return ans;
}
