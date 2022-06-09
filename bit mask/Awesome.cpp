// https://www.learning.algozenith.com/problems/Awesome-967

/*

Description

Given a string 
s
. An awesome substring is a non-empty substring of 
s
 such that we can make any number of swaps in order to make it a palindrome.

Find the length of the maximum length awesome substring of 
s
.


Input Format

First-line contains 
T
 - the number of test cases.
The first line of each test case contains string 
s
.


Output Format

For each test case, output the length of the maximum length awesome substring of 
s
.


Constraints

1
≤
T
≤
10
5

1
≤
|
s
|
≤
10
5

String 
s
 only contains digts from 
0
−
9
.
Sum of 
|
s
|
 over all test cases is 
≤
10
6
.


Sample Input 1

3
185801630663498
213123
123456

Sample Output 1

5
6
1

*/


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int Awesome(string s) {
    int mask = 0, ans = 0;
    vector<int> m(1 << 10, s.size() + 1);
    m[0] = -1;
    for (int i = 0; i < s.size(); i++) {
        mask ^= (1 << (s[i] - '0'));
        for (int j = 0; j < 10; j++) {
            ans = max(ans, i - m[mask ^ (1 << j)]);
        }
        ans = max(ans, i - m[mask]);
        m[mask] = min(m[mask], i);
    }
    return ans;
}
void solve() {
    string s;
    cin >> s;
    cout << Awesome(s) << endl;
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
