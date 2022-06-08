// https://www.learning.algozenith.com/problems/Big-Factorial-844

/*

Description

Given an integer N, find its factorial.


Input Format

Given an integer N  in a single line.


Output Format

Output N! in a single line.


Constraints

1 ≤ N ≤ 1000

Sample Input 1

5

Sample Output 1

120

Sample Input 2

21

Sample Output 2

51090942171709440000

*/


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'
vector<int> factorial(int N) {
    vector<int> ans = {1}; // initialised factorial value as 1.
    for (int i = 1; i <= N; i++) {

        // multipliying current ans = (i-1)! with i, to get ans = i!
        int carry = 0;
        for (int j = 0; j < ans.size(); j++) { //multiplying each digit of ans with i and carrying the value.
            int p = ans[j] * i + carry;
            carry = p / 10;
            ans[j] = p % 10;
        }
        // adding the last over carry value.
        while (carry) {
            int r = carry % 10;
            carry /= 10;
            ans.push_back(r);
        }
        // now ans = i!
    }
    reverse(ans.begin(), ans.end()); // N! will be stored in reversed way in ans vector.
    return ans;
}
void solve() {
    int n;
    cin >> n;
    auto v = factorial(n);
    for (auto x : v)cout << x;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
