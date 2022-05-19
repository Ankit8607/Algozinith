// https://www.learning.algozenith.com/problems/Maximum-Area-of-Square-475

/*

Description

Given a grid of size n*m with 0s and 1s, you need to find the area of the largest square containing only 1.


Input Format

The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first line of each test case contains two space-separated integers n, m - the size of the grid.

Each of the next n lines contains m space-separated integers, aij - the number at that cell.


Output Format

For each test case, print the maximum area.


Constraints

1 ≤ t ≤ 105

1 ≤ n, m ≤ 103

0 ≤ aij ≤ 1

It is guaranteed that the sum of n*m over all test cases does not exceed 107.


Sample Input 1

3
2 3
0 1 1
0 0 0
3 3
1 0 1
0 1 1
0 1 1
2 2
0 0
0 0

Sample Output 1

1
4
0

*/


#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n,m,ans=0;
	cin>>n>>m;
    vector<vector<int>> v(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>v[i][j];
            if(v[i][j]){
                v[i][j]+=min({v[i-1][j],v[i][j-1],v[i-1][j-1]});
                if(v[i][j]>ans)
                    ans=v[i][j];
            }
        }
    }
    cout<<ans*ans<<'\n';
}

//Think twice code once

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    
    int t;cin>>t;while(t--)
    solve();
}
