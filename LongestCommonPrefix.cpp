string Solution::longestCommonPrefix(vector<string> &A) {
    sort(A.begin(),A.end());
    int len = min(A[0].size(),A[A.size()-1].size());
    int i=0;
    string first = A[0],last = A[A.size()-1];
    while(i<len and first[i]==last[i])
        i++;
    return first.substr(0,i);
}
