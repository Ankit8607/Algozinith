// https://www.learning.algozenith.com/problems/COUNTBIT-619

/*

Description

Given a positive integer N, count the total number of set bits in binary representation of all numbers from 1 to N.


Input Format

The first line contains a single integer T - the number of test cases.
T lines follow each containing a single integer N.


Output Format

For each test case print the number of set bits in all numbers from 1 to N.


Constraints

1 ≤ T ≤ 105

0 ≤ N ≤ 108


Sample Input 1

4
3
4
7
8

Sample Output 1

4
5
12
13

Note

For N = 4:
1 : 001
2 : 010
3 : 011
4 : 100
Total number of set bits is 1+1+2+1 = 5

*/


#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    n++;
    int ans=0;
    int per=2;
    int i=0;
    while(n>=(1<<i)){
        ans+=(n/per)*(1<<i);
        ans+=max(0,n%per-per/2);
        i++;
        per<<=1;
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
        int n;
        cin >> n;
        cout << countSetBits(n) << '\n';
    }

    return 0;
}
