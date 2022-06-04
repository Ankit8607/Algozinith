// https://www.learning.algozenith.com/problems/SWAPBIT-577

/*

Description

Given an unsigned integer N you have to swap all odd bits with even bits. For example, 53 (110101) is converted to 58 (111010).

Try to do it in O(1).


Input Format

The first line contains T - the number of test cases.
T lines follow each containing a single integer N.


Output Format

Print the modified integer for every test case in a new line.


Constraints

1 ≤ T ≤ 105
1 ≤ N ≤ 108


Sample Input 1

5
1
2
3
53
23


Sample Output 1

2
1
3
58
43


Note

1 (01) -> 2 (10)
2 (10) -> 1 (01)
3 (11) -> 3 (11)

*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int even_mask = 0xAAAAAAAA, odd_mask = 0x55555555;

        int even_bits = n & even_mask, odd_bits = n & odd_mask;

        even_bits >>= 1;
        odd_bits <<= 1;

        cout << (even_bits | odd_bits) << '\n';
    }
}
