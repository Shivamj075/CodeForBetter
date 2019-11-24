/*

Aggressive cows
Farmer John has built a new long barn, with N stalls. Given an array of integers A of size N where each element of the array 
represents the location of the stall, and an integer B which represent the number of cows. His cows don't like this barn layout
and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, John wants to assign 
the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum
distance? 
Input Format
The first argument given is the integer array A.
The second argument given is the integer B.
Output Format
Return the largest minimum distance possible among the cows.
Constraints
2 <= N <= 100000
0 <= A[i] <= 10^9
2 <= B <= N
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = 3
Output 1:
    2

Input 2:
    A = [5, 17, 100, 11]
    B = 2
Output 2:
    95
   */
   
   bool chk(vector<int>&A,int B,int mid){
    int total=1,pos=A[0];
    for(int i=1;i<A.size();i++){
        if(A[i]-pos>=mid){
            total++;
            pos=A[i];
        }
        if(total>=B)
            return true;
    }
    return false;
}
int Solution::solve(vector<int> &A, int B) {
    long long s=0,e=1000000000;
    int ans;
    sort(A.begin(),A.end());
    while(s<=e){
        int mid=s+(e-s)/2;
        if(chk(A,B,mid)){
            ans=mid;
            s=mid+1;
        }
        else
            e=mid-1;
    }
    return ans;
}
