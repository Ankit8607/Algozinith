// https://www.learning.algozenith.com/problems/Bubbles-962

/*

Description

You are given 
n
 bubbles, indexed from 
0
 to 
n
−
1
. Each bubble is painted with a number on it represented by an array 
n
u
m
s
. You are asked to burst all the bubbles.

If you burst the 
i
t
h
 bubble, you will get 
n
u
m
s
[
i
−
1
]
∗
n
u
m
s
[
i
]
∗
n
u
m
s
[
i
+
1
]
 coins. If 
i
−
1
 or 
i
+
1
 goes out of bounds of the array, then treat it as if there is a bubble with a 
1
 painted on it.

Find the maximum coins you can collect by bursting the bubbles wisely.


Input Format

The First line contains 
T
 - the number of test cases.
The first line of each test case contains 
n
.
The second line of each test case contains 
n
 elements of the array 
n
u
m
s
.


Output Format

For each test case, Output the maximum coins you can collect by bursting the bubbles wisely.


Constraints

1
≤
T
≤
200

1
≤
n
≤
200

0
≤
n
u
m
s
[
i
]
≤
100

Sample Input 1

4
4
3 1 5 8
2
1 5
1
10
3
5 0 5

Sample Output 1

167
10
10
30

*/


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

vector<vector<int>> dp;
int rec(int i, int j, vector<int>&nums) {
    if (i > j)return 0;
    auto &ans = dp[i][j];
    if (ans != -1)return ans;
    ans = 0;
    for (int k = i + 1; k < j; k++) {
        ans = max(ans, rec(i, k, nums) + rec(k, j, nums) + nums[k] * nums[i] * nums[j]);
    }
    return ans;
}
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    dp.assign(n + 2, vector<int>(n + 2, -1));
    vector<int> nums2(n + 2);
    nums2[0] = nums2[n + 1] = 1;
    for (int i = 0; i < n; i++)nums2[i + 1] = nums[i];
    return rec(0, n + 1, nums2);
}
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    cout << maxCoins(v) << endl;
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
