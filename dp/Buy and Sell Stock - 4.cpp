// https://www.learning.algozenith.com/problems/Buy-and-Sell-Stock---4-261

/*

Description

You are given N integers, the price of a given stock on each day. You can buy and sell at most K stocks. You cannot buy a stock before you sell the previous stock. You cannot sell a stock before you buy one. You have to find the maximum profit you can make by buying and selling stocks.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains two space-separated integers N and K - the length of the array the maximum number of stocks you can buy.
The second line of each test case contains N space-separated integers.
Sum of N x K across all test cases ≤ 10^8.


Output Format

For each test case, print the maximum profit you can make by buying and selling stocks.


Constraints

1≤ T ≤ 100

1 ≤ K ≤ N

1≤ N ≤ 105

0≤ Ai ≤ 105

Sum of N*K across all test cases ≤ 10^8.


Sample Input 1

4
7 1
4 3 8 7 6 0 2
7 4
4 3 8 7 6 0 2
4 3
1 2 3 4
4 1
5 3 2 1

Sample Output 1

5
7
3
0

Note

For the first test case, you can buy stock on day 2 and sell on day 3. Profit = 8-3 = 5

For the second test case, you can buy stock on day 2 and sell on day 3 and again buy on day 6 and sell on day 7. Profit = (8-3) + (2-0) = 5+2 = 7

For the third test case, you can buy stock on day 1 and sell on day 4. Profit = 4-1 = 3

For the fourth test case, you don’t buy and sell any stock. Profit = 0

*/


#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

long long BuyAndSellStock(vector<int> &a, int k)
{
    int n = (int)a.size();
    if (2 * k > n)
    {
        long long ans = 0;
        for (long long i = 1; i < n; ++i)
            ans += max(0, a[i] - a[i - 1]);
        return ans;
    }
    else
    {
        long long dp[k + 1][n];
        memset(dp, 0, sizeof(dp));
        for (long long i = 1; i <= k; ++i)
        {
            long long m = -a[0];
            for (long long j = 1; j < n; ++j)
            {
                dp[i][j] = max(dp[i][j - 1], a[j] + m);
                m = max(m, dp[i - 1][j - 1] - a[j]);
            }
        }
        return dp[k][n - 1];
    }
}

int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (long long i = 0; i < n; ++i)
            cin >> a[i];

        cout << BuyAndSellStock(a, k) << "\n";
    }
    return 0;
}
