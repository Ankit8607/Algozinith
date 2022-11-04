// https://www.learning.algozenith.com/problems/Subtraction-Game-1072

/*

Description

Vivek and Abhishek are playing a game of chips, taking turns alternatively. Initially, there are 
x
 chips on the table. On each turn, a player can pick up 
2
m
 chips such that 
m
≥
0
 and 
x
≥
2
m
. A player loses the game if he has no chips to pick from the table.

Given that Vivek starts the game, Predict the winner of the game.


Input Format

The first line contains 
T
 - the number of test cases.
The next 
T
 lines contain an integer 
x
, - the number of chips on the table.


Output Format

For each test case, Predict the winner of the chip game. Output "Vivek" if Vivek wins; else output "Abhishek", on a new line.


Constraints

1
≤
T
≤
10
6
.
0
≤
x
≤
2
×
10
5
.


Sample Input 1

5
0 
2
12783
1001
33

Sample Output 1

Abhishek
Vivek
Abhishek
Vivek
Abhishek

*/

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

vector<int> dp;
int rec(int x) {
    if (x == 0)return 0;
    if (__builtin_popcount(x) == 1)return 1;
    auto &ans = dp[x];
    if (ans != -1)return ans;
    ans = 1;
    for (int j = 0; (1 << j) <= x; j++) {
        ans &= rec(x - (1 << j));
    }
    ans ^= 1;
    return ans;
}
void solve() {
    dp.assign((int)2e5 + 10, -1);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto ans = rec(n);
        if (ans)cout << "Vivek" << endl;
        else cout << "Abhishek" << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}
