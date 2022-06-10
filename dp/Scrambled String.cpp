// https://www.learning.algozenith.com/problems/Scrambled-String-898

/*

Description

We can scramble a string 
s
 to get a string 
t
 using the following algorithm:

If the length of the string is 
1
, stop.

If the length of the string is 
>
1
, do the following:
2.1 Split the string into two non-empty substrings at a random index, i.e., if the string is 
s
, divide it to 
x
 and 
y
 where 
s
=
x
+
y
.
2.2 Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, 
s
 may become 
s
=
x
+
y
 or 
s
=
y
+
x
.

Apply step 
1
 recursively on each of the two substrings 
x
 and 
y
.


Input Format

The first-line contains 
T
 - the number of test cases.
Each test case contains two strings 
s
1
 and 
s
2
 of the same length.


Output Format

For each test case, output "Yes" if 
s
2
 is a scrambled string of 
s
1
, otherwise, output "No", in a newline.


Constraints

1
≤
T
≤
100

s
1.
l
e
n
g
t
h
==
s
2.
l
e
n
g
t
h

1
<=
s
1.
l
e
n
g
t
h
<=
40

s
1
 and 
s
2
 consist of lower-case English letters.


Sample Input 1

3
abcde caebd
a a
great rgeat

Sample Output 1

No
Yes
Yes

Note

For test case 
3
,
One possible scenario applied on s1 is:

"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now and the result string is "rgeat" which is 
s
2
.
As there is one possible scenario that led s1 to be scrambled to 
s
2
, we ouput "Yes".

*/



#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int dp[41][41][41];
string s1, s2;
bool rec(int l, int r, int i) {
    int j = i + r - l; // relationship... to reduce DP state.
    if (l > r || i > j)return false;
    if (l == r) {
        if (s1[l] == s2[i])return true;
        return false;
    }
    auto &ans = dp[l][r][i];
    if (ans != -1)return ans;
    ans = 0;
    if (s1.substr(l, r - l + 1) == s2.substr(i, j - i + 1))return ans = 1;
    for (int k = l; k < r; k++) {
        ans |= (rec(l, k, i)&rec(k + 1, r, i + k - l + 1));
        ans |= (rec(l, k, j - (k - l + 1) + 1)&rec(k + 1, r, i));
    }
    return ans;
}
void solve() {
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    if (rec(0, s1.size() - 1, 0)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
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
