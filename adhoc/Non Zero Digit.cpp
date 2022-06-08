// https://www.learning.algozenith.com/problems/Non-Zero-Digit-854

/*

Description

You will be given an array A of N non-negative integers. Your task is to find the rightmost non-zero digit in the product of array elements if exist.


Input Format

First-line contains N, the size of the array A.
The second line contains N non-negative integers. 


Output Format

Print the rightmost non-zero digit in the product of array elements, if there is no rightmost non-zero digit, then print -1.


Constraints

1 ≤ N ≤ 105
0 ≤ A[i] ≤ 105 

Sample Input 1

4
3 23 30 45

Sample Output 1

5

Sample Input 2

5
1 0 2 3 4

Sample Output 2

-1

Note

For Sample 1: Product of these numbers are 93150. Rightmost non-zero digit is 5.

*/



#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    int a[n];
    bool flag = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0)flag = false;
    }
    if (!flag) { // when product of elements if 0.
        cout << -1;
        return;
    }
    int cnt2 = 0, cnt5 = 0;
    for (int i = 0; i < n; i++) { // counting  frequency of 2 and 5 in the product.
        int x = a[i];
        while (x % 2 == 0)cnt2++, x /= 2;
        while (x % 5 == 0)cnt5++, x /= 5;
    }
    int tens = min(cnt2, cnt5); // number of ending zeroes in the final product.
    cnt2 = cnt5 = tens; // 2 and 5 cnts to be removed from product, to remove all ending zeroes.
    ll prod = 1;
    for (int i = 0; i < n; i++) { // O(n*logn)
        while (cnt2 && a[i] % 2 == 0)cnt2--, a[i] /= 2;
        while (cnt5 && a[i] % 5 == 0)cnt5--, a[i] /= 5;
        (prod *= a[i]) %= 10; // prod will always have last non zero digit.
    }
    cout << prod;
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
