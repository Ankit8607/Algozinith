// https://www.learning.algozenith.com/problems/Maximum-Sum-in-Grid-478

/*

Description

Given a grid of size n x m with integers, you need to find the maximum sum Subgrid.


Input Format

The first line of the input contains one integer t - the number of test cases. Then t test cases follow.
The first line of each test case contains two space-separated integers n, m - the size of the grid.
Each of the next n lines contains m space-separated integers, a[i][j] - the number at the cell (i, j).


Output Format

For each test case, print the maximum sum.


Constraints

1 ≤ t ≤ 105
1 ≤ n, m ≤ 105
-105 ≤ a[i][j] ≤ 105

It is guaranteed that the sum of n x m over all test cases does not exceed 105.


Sample Input 1

3
2 3
10 2 -1
-4 5 -1
2 2
-1 -1
-1 -1
2 2
1 2
3 4

Sample Output 1

13
-1
10

Note

For the first test case, the top left 2 x 2 subgrid, 10 + 2 - 4 + 5 = 13.

For the second test case, all cells have a maximum sum which is -1.

For the third test case, all cells are positive, maximum sum subgrid is the entire grid with sum 10.

*/


#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")//use pragma's only for GCC compilers

using namespace std;

void solve(){
	int n,m,i,j,k;
    cin>>n>>m;
    vector<vector<long long>> v(n+1,vector<long long>(m+1));
    
    long long ans=-1e18,s;
    if(n>m){
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                cin>>v[i][j];
                v[i][j]+=v[i][j-1];
            }
        for(i=1;i<=m;i++){
            for(j=i;j<=m;j++){
                s=0;
                for(k=1;k<=n;k++){
                    s+=v[k][j]-v[k][i-1];
                    if(s>ans)
                        ans=s;
                    if(s<0)
                        s=0;
                }
            }
        }
    }else{
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                cin>>v[i][j];
                v[i][j]+=v[i-1][j];
            }
        for(i=1;i<=n;i++){
            for(j=i;j<=n;j++){
                s=0;
                for(k=1;k<=m;k++){
                    s+=v[j][k]-v[i-1][k];
                    if(s>ans)
                        ans=s;
                    if(s<0)
                        s=0;
                }
            }
        }
    }
    cout<<ans<<'\n';
}

//Think twice code once

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    
    int t;cin>>t;while(t--)
    solve();
}
