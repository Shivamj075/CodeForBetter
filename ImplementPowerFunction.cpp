/*
https://www.interviewbit.com/problems/implement-power-function/

Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.

*/


int Solution::pow(int x, int n, int p) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
   if (n == 0) 
        return 1 % p;

    long long ans = 1, base = x;
    while (n > 0) 
    {
        if (n % 2 == 1)
        {
            ans = (ans * base) % p;
            n--;
        } 
        else
        {
            base = (base * base) % p;
            n /= 2;
        }
    }
    if (ans < 0) 
        ans = (ans + p) % p;
    return ans;
}
