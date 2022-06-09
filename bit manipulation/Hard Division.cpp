// https://www.learning.algozenith.com/problems/Hard-Division-942

/*

Description

Given two integers 
d
i
v
i
d
e
n
d
 and 
d
i
v
i
s
o
r
, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 
8.345
 would be truncated to 
8
, and 
−
2.7335
 would be truncated to 
−
2
.

Return the quotient after dividing the dividend by the divisor.

Note:
Assume we are dealing with an environment that could only store integers within the 
32
-bit signed integer range: 
[
−
2
31
,
2
31
−
1
]
.
( This means no long long or unsigned int )
For this problem, if the quotient is strictly greater than 
2
31
−
1
, then return 
2
31
−
1
, and if the quotient is strictly less than 
−
2
31
, then return 
−
2
31
.
No multiplication, division, or mod operator.

Input Format

The First line contains 
T
 - the number of test cases.
The first line of each test case contains two integers - 
d
i
v
i
d
e
n
d
 and 
d
i
v
i
s
o
r
.


Output Format

For each test case, output the 
q
u
o
t
i
e
n
t
 after dividing 
d
i
v
i
d
e
n
d
 by 
d
i
v
i
s
o
r
.


Constraints

1
≤
T
≤
10
5
.
−
2
31
≤
d
i
v
i
d
e
n
d
,
d
i
v
i
s
o
r
≤
2
31
−
1
.
d
i
v
i
s
o
r
≠
0
.


Sample Input 1

8
-2147483648 -1
-2147483648 1
-2147483648 -2147483648
-2147483648 2147483647
10 3
7 -3
0 1
1 5

Sample Output 1

2147483647
-2147483648
1
-1
3
-2
0
0

*/


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int divide(int dividend, int divisor) {

    // Edge Case-: INT_MIN
    if (dividend == INT_MIN) {
        if (divisor == -1) {return INT_MAX;}
        else if (divisor == INT_MIN) {return 1;}
        else if (divisor < 0) {
            // do this so we can avoid abs(dividend) overflowing the upper int limit
            return 1 + divide(dividend - divisor, divisor);
        }
        else {
            // same as above comment
            return -1 + divide(dividend + divisor, divisor);
        }
    }
    else if (divisor == INT_MIN) {return 0;}


    int ans = 0, sign = 1; // keeping track of sign.
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))sign = -1;

    dividend = abs(dividend), divisor = abs(divisor); // taking both +ve value.

    for (int i = __builtin_clz(divisor) - 1; i >= 0; i--) {
        if (dividend >= (divisor << i))dividend -= (divisor << i), ans += (1 << i);
    }

    return sign * ans;
}
void solve() {
    int a, b;
    cin >> a >> b;
    cout << divide(a, b) << endl;
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
