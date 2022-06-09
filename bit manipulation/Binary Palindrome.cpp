// https://www.learning.algozenith.com/problems/Binary-Palindrome-970

/*

Description

Given an integer 
n
, find the 
n
t
h
 positive number whose binary representation is a palindrome.

Note:
Do not consider the leading zeros, while considering the binary representation.


Input Format

The first line contains 
T
 - the number of test cases.
First line of each test case contains 
n
.


Output Format

For each test case, output the 
n
t
h
 positive number whose binary representation is a palindrome.


Constraints

1
≤
T
≤
10
6

1
≤
n
≤
10
6

Sample Input 1

5
1
2
1000000
10
11

Sample Output 1

1
3
302780951
31
33

*/


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int nth_palindrome(int n) {
    int cnt = 1, p = 1, l = 0;
    while (1) {
        l++;
        if (cnt + p > n) break;
        cnt += p;
        l++;
        if (cnt + p > n) break;
        cnt += p;
        p *= 2;
    }

    int off = n - cnt;
    vector<bool> bits(l, 0);
    bits[0] = bits[l - 1] = 1;
    int mid = l / 2;
    for (int i = 0; off && i < mid; i++)
    {
        if (l & 1) {
            bits[mid + i] = bits[mid - i] = (off & 1);
        }
        else {
            bits[mid - i - 1] = bits[mid + i] = (off & 1);
        }
        off /= 2;
    }
    int64_t ans = 0, x = 1;
    for (int i = 0; i < l; i++) {
        ans += bits[i] * x;
        x <<= 1;
    }

    return ans;

}
void solve() {
    int n;
    cin >> n;
    cout << nth_palindrome(n) << endl;
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
