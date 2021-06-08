// { Driver Code Starts
//Initial template for C++
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;
#define cpp_int unsigned long long

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find the nth catalan number.

    cpp_int findCatalan(int n)
    {

        if (n <= 1)
            return 1;

        int i, j;
        cpp_int dp[n + 1];
        // cpp_int i, j;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;

        for (i = 2; i <= n; i++)
        {
            for (j = 0; j < i; j++)
            {
                dp[i] += (dp[j]) * (dp[i - j - 1]);
                // cout<<"i "<<i<<"  j "<<i-j-1<<"  "<<dp[i]<<endl; 
            }
        }

        return (cpp_int)dp[n];
    }
};

// { Driver Code Starts.

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //taking count of testcases
    int t;
    cin >> t;
    while (t--)
    {

        //taking nth number
        int n;
        cin >> n;
        Solution obj;
        //calling function findCatalan function
        cout << obj.findCatalan(n) << "\n";
    }
    return 0;
} // } Driver Code Ends