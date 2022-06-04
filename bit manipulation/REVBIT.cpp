// https://www.learning.algozenith.com/problems/REVBIT-611

/*

Description

Given an unsigned 32-bit integer N, reverse its bits and print the reversed number.


Input Format

The first line contains a single integer T - the number of test cases.
T lines follow each containing a single integer N.


Output Format

For each test case print the reversed number in a new line.


Constraints

1 ≤ T ≤ 104

1 ≤ N < 232


Sample Input 1

4
1
2
10
15

Sample Output 1

2147483648
1073741824
1342177280
4026531840

Note

1 (00000000000000000000000000000001) => 2147483648 (10000000000000000000000000000000)

2 (00000000000000000000000000000010) => 1073741824 (01000000000000000000000000000000)

*/



#include <bits/stdc++.h>
using namespace std;

unsigned int reverseBits(unsigned int n)
{
    unsigned int ans=0;
    for(int i=0;i<32;i++){
        if((1<<i)&n){
            ans|=(1<<(31-i));
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        unsigned int n;
        cin >> n;
        cout << reverseBits(n) << '\n';
    }
    return 0;
}
