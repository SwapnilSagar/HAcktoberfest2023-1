#include <bits/stdc++.h>
using namespace std;

// int helper(int n, vector<int>&v, int k,vector<int> dp)
// {
//     if(n==0)
//     {
//         return 0;
//     }
//     if(dp[n]!= -1) return dp[n];
//     int m=INT_MAX;

//     for(int i=1;i<=k;i++)
//     {
//         int jmp=INT_MAX;
//         if(n>=i)
//             jmp=helper(n-i,v,k,dp) + abs(v[n]-v[n-i]);
//         m=min(m,jmp);
//     }

//     return dp[n]=m;
// }

int frogjump(int n, vector<int> &v, int k)
{
    vector<int> dp(n, -1);
    // return helper(n-1,v,k,dp);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int m = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            int jmp = INT_MAX;
            if (i >= j)
            {
                jmp = dp[i - j] + abs(v[i] - v[i - j]);
            }
            m = min(m, jmp);
        }
        dp[i] = m;
    }
    return dp[n - 1];
}

int main()
{
    int n = 6;
    vector<int> v(n);
    v = {10, 40, 60, 30, 60, 40};
    int k;
    cin >> k;
    int ans = frogjump(n, v, k);
    cout << ans;
    return 0;
}