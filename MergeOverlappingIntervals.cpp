/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool cmp(Interval a, Interval b){
     return a.start<b.start;
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end(),cmp);
    int s=A[0].start,e=A[0].end;
    vector<Interval> ans;
    int cnt=0;
    for(int i=1;i<A.size();i++){
        int s1=A[i].start,e1=A[i].end;
        if(s1>=s and s1<=e){
            if(e1>e)
                e=e1;
        }
        else{
            Interval elem;
            elem.start=s,elem.end=e;
            ans.push_back(elem);
            s=A[i].start;
            e=A[i].end;
            cnt++;
        }
    }
    Interval elem;
    elem.start=s,elem.end=e;
    ans.push_back(elem);
    return ans;
}
