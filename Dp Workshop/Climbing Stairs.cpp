// https://www.learning.algozenith.com/problems/Climbing-Stairs-1036

/*

Description

You are climbing a staircase. It takes 
N
 steps to reach the top.

Each time you can either climb 
1
 or 
M
 steps. What is the minimum number of climbs you need to do to reach the top, i.e., 
N
th stair?


Input Format

The first line of input contains 
T
 - the number of test cases. Then 
T
 test cases follow.
The only line of each test case contains two space-separated integers - 
N
 and 
M
.


Output Format

For each test case, print the minimum number of climbs require to climb the top on a new line.


Constraints

1
≤
T
≤
10
6

1
≤
M
≤
N
≤
10
9

Sample Input 1

2
5 1
6 4

Sample Output 1

5
3

Note

For the first test case, we can reach top by 
0
→
1
→
2
→
3
→
4
→
5
.

For the second test case, we can reach top by 
0
→
1
→
5
→
6
.

*/


#include<bits/stdc++.h>
using namespace std;
const int mod= 10000007;
#define endl "\n" 
#define all(a) a.begin(),a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve(){
    int n,m; cin>>n>>m;
    int ans=n/m;
    n=n-ans*m;
    ans+=n;
    cout<<ans<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
