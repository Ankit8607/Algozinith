// https://www.learning.algozenith.com/problems/INTBREAK-610

/*

Description

Given an integer N, break it into the sum of K positive integers, where K >= 2, and maximize the product of those integers.


Input Format

The first line contains a single integer T - the number of test cases.
T lines follow containing a single integer N.


Output Format

For each test case print in a new line the maximum output possible modulo 109+7.


Constraints

1 ≤ T ≤ 104
2 ≤ N ≤ 106


Sample Input 1

5
2
3
4
5
10

Sample Output 1

1
2
4
6
36

Note

1 + 1 = 2
1 + 2 = 3
2 + 2 = 4
2 + 3 = 5
3 + 3 + 4 = 10

*/


#include <bits/stdc++.h>
using namespace std;
long long mod=1000000007;

int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=(1LL*ans*a)%mod;
        a=(1LL*a*a)%mod;
        b>>=1;
    }
    return ans;
}

int findMaxProd(int n)
{
    if(n<4) return n-1;
    int ans=0;
    if(n%3==0) return power(3,n/3);
    if(n%3==1) return 4LL*power(3,(n-4)/3) %mod;
    else return 2*power(3,n/3) %mod;
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
        cout << findMaxProd(n) << '\n';
    }
    return 0;
}
