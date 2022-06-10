// https://www.learning.algozenith.com/problems/Longest-Common-Substring-899

/*

Description

Given two strings. The task is to find the length of the longest common substring.


Input Format

First-line contains 
T
 - the number of test cases.
Each test case contains two strings 
s
1
 and 
s
2
 in a single line.


Output Format

For each test case, output the length of the longest common substring of the two strings, in a new line.


Constraints

1
≤
T
≤
100

1
≤
|
s
1
|
≤
1000

1
≤
|
s
2
|
≤
1000

s
1
 and 
s
2
 contains small letters only.


Sample Input 1

3
abc abc
algozenith algo
algo zenith

Sample Output 1

3
4
0

*/

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

string s1, s2;
int n, m;
int dp[1001][1001];
int rec(int i, int j) {
    if (i == n || j == m)return 0;
    auto &ans = dp[i][j];
    if (ans != -1)return ans;
    ans = 0;
    if (s1[i] == s2[j])ans = max(ans, 1 + rec(i + 1, j + 1));
    rec(i + 1, j), rec(i, j + 1);
    return ans;
}
void solve() {
    cin >> s1 >> s2;
    n = s1.size(), m = s2.size();
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)ans = max(ans, rec(i, j));
    }
    cout << ans << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
