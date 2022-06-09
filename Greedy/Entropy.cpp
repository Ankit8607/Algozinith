// https://www.learning.algozenith.com/problems/Entropy-955

/*

Description

You are given an integer array 
n
u
m
s
 of size 
n
 and an integer 
k
.

For each index 
i
 where 
0
≤
i
<
n
, change 
n
u
m
s
[
i
]
 to be either 
n
u
m
s
[
i
]
+
k
 or 
n
u
m
s
[
i
]
−
k
.

The Entropy of 
n
u
m
s
 is the difference between the maximum and minimum elements in 
n
u
m
s
.

Return the minimum Entropy of nums after changing the values at each index.


Input Format

First-line contains 
T
 - the number of test cases.
First line of each test case contains 
n
 - the size of the 
n
u
m
s
 and 
k
.
Second line of each test case contains 
n
 elements of 
n
u
m
s
.


Output Format

For each test case, output the minimum Entropy of nums after changing the values at each index.


Constraints

1
≤
T
≤
10
4
.
1
≤
n
≤
10
5
.
0
≤
k
≤
10
4
.
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
10
4
.

Sum of 
n
 over all test cases is 
≤
 
10
6
.


Sample Input 1

3
3 3
1 3 6
1 0
1
3 1
2 2 7

Sample Output 1

3
0
3

*/


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int Entropy(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = nums[n - 1] - nums[0];
    for (int i = 1; i < n; i++) {
        int mx = max(nums[n - 1] - k, nums[i - 1] + k); // because nums[n-1] may still remain max.
        int mn = min(nums[0] + k, nums[i] - k); // because nums[0] may still remain min.
        ans = min(ans, mx - mn);
    }
    return ans;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    cout << Entropy(v, k) << endl;
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
