/*
https://www.interviewbit.com/problems/reverse-the-string/

Given a string A.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.

Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

If there are multiple spaces between words, reduce them to a single space in the reversed string.



Input Format

The only argument given is string A.
Output Format

Return the string A after reversing the string word by word.
For Example

Input 1:
    A = "the sky is blue"
Output 1:
    "blue is sky the"

Input 2:
    A = "this is ib"
Output 2:
    "ib is this"

*/

string Solution::solve(string A) {
    int n=A.size();
    string ans="",temp="";
    for(int i=n-1;i>=0;i--){
        char c=A[i];
        if(c!=' ')
            temp+=c;
        else{
            for(int j=temp.size()-1;j>=0;j--)
                ans+=temp[j];
            ans+=' ';
            temp="";
        }
    }
    for(int j=temp.size()-1;j>=0;j--)
        ans+=temp[j];
    return ans;
}
