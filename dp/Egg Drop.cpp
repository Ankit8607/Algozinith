// https://www.learning.algozenith.com/problems/Egg-Drop-600

/*

Description

You are in a building with n floors labeled from 1 to n. You have k identical eggs with you.
You also know that there exists a floor f (0 <= f <= n) such that any egg dropped at a floor higher than f will break, and any egg dropped at floor f or below will not break.
In one move you can select an unbroken egg and drop it from any floor x (1 <= x <= n). If the egg breaks you can no longer use it. However, if the egg does not break, you can reuse it in your further moves.
Find the minimum number of moves you need to make to determine with certainty the value of f.


Input Format

The only line of input contains two space-separated integers n and k.


Output Format

Print the minimum number of moves you need to make.


Constraints

1 <= n <= 10000
1 <= k <= 100

Sample Input 1

2 1

Sample Output 1

2

Sample Input 2

14 3

Sample Output 2

4

Note

Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

*/


#include <bits/stdc++.h>
using namespace std;
int EggDrop(int N, int K)
{
    vector<int> dp(N + 1);
    for (int i = 0; i <= N; i++)
        dp[i] = i;
    for (int k = 2; k <= K; k++)
    {
        vector<int> dp2(N + 1, 0);
        int x = 1;
        for (int n = 1; n <= N; n++)
        {
            while (x < n && max(dp[x - 1], dp2[n - x]) > max(dp[x], dp2[n - x - 1]))
                x++;
            dp2[n] = 1 + max(dp[x - 1], dp2[n - x]);
        }
        dp = dp2;
    }
    return dp[N];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;

    cout << EggDrop(N, K) << "\n";
}
