// https://www.learning.algozenith.com/problems/Tricky-Sum-914

/*

Description

Given two integers 
a
 and 
b
, return the sum of the two integers without using the operators 
+
 and 
−
.


Input Format

First-line contains 
T
 - the number of test cases.
The first line of each test case contains two integers 
a
 and 
b
.


Output Format

For each test case in a newline, output the sum of 
a
 and 
b
.


Constraints

1
≤
T
≤
2
×
10
6

−
1000
≤
a
,
b
≤
1000

Sample Input 1

2
2 1
-1 1

Sample Output 1

3
0

*/


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int Sum(int a, int b) {
    while (b) {
        unsigned int c = (a & b); // carry.
        a ^= b;
        b = (c << 1);
    }
    return a;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << Sum(a, b) << endl;
    assert(a + b == Sum(a, b));
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
