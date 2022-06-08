// https://www.learning.algozenith.com/problems/BLAWHI-579

/*

Description

Given a chessboard of size N × M, find the number of ways in which you can place 2 knights - one black and one white, such that they do not attack each other.


Input Format

The one and only line of each input file contains two integers - N and M.


Output Format

Print the possible number of arrangements modulo 109 +7.


Constraints

1 ≤ N,M ≤ 105
1 < N x M


Sample Input 1

2 2


Sample Output 1

12


Sample Input 2

2 3


Sample Output 2

26

*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int MOD = 1e9 + 7;

int main()
{
    ll n, m;
    cin >> n >> m;

    ll tot = (n * m % MOD) * ((n * m - 1) % MOD) % MOD; //tot = (n*m)*(n*m-1)
    ll att = max(0LL, n - 1) * max(0LL, m - 2) * 4 % MOD;
    (att += max(0LL, n - 2) * max(0LL, m - 1) * 4 % MOD) %= MOD;

    cout << (tot - att + MOD) % MOD << '\n';

    return 0;
}
