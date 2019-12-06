/*
InterviewBit
Largest Number

Given a list of non negative integers, arrange them such that they form the largest number. For example: Given [3, 30, 34, 5, 9], 
the largest formed number is 9534330. Note: The result may be very large, so you need to return a string instead of an integer.

/*

bool cmp(string x,string y){
    string xy = x.append(y);
    string yx = y.append(x);
    return xy>yx;
}
string Solution::largestNumber(const vector<int> &A) {
    //string s = to_str
    vector<string> s;
    for(int i=0;i<A.size();i++)
        s.push_back(to_string(A[i]));
    sort(s.begin(),s.end(),cmp);
    string ans;
    for(int i=0;i<A.size();i++){
        ans+=s[i];
    }
    int i=0;
    while(ans[i]=='0'){
            i++;
    }
    if(i==ans.size())
        return "0";
    return ans;
}
