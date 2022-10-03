// https://www.learning.algozenith.com/problems/Bricks-Colouring-170

/*

Description

You are given N bricks in a line and M different coloured buckets of paint. You have to find the number of ways you can colour the brick wall such that there are exactly K positions out of the N bricks such that it has a different colour from the brick wall on its immediate left. (except the first brick, since there is no left brick). Print it modulo 10^9+7.

 

 


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first and only line of each test case contains three space-separated integers N, M, K.

 


Output Format

For each test case, print the number of ways you can colour the brick wall satisfying the given condition % 10^9+7.


Constraints

1≤ T ≤ 100

1≤ N, M ≤ 2000

0≤ K ≤ N-1

It is guaranteed that the sum of NK over all test cases does not exceed 4108.


Sample Input 1

3
3 2 2
2 2 1
3 5 0

Sample Output 1

2
2
5

*/

#include<bits/stdc++.h>
using namespace std;
const int mod= 1000000007;
#define endl "\n"
#define F first
#define S second
#define vi vector<int>
#define ii pair<int,int>
#define all(a) a.begin(),a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define tracearray(arr,n)  cout<<#arr<<endl;for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;

int n,m;

int rec(int level,int k,vector<vector<int>>&dp){
    if(k<0) return 0;
    if(level==n) return k==0;

    if(dp[level][k]!=-1) return dp[level][k];

    return dp[level][k]=(1LL*(m-1)*rec(level+1,k-1,dp)%mod+rec(level+1,k,dp)%mod)%mod;
}

void solve(){
    int k;
    cin>>n>>m>>k;
    vector<vector<int> >dp(n,vector<int>(k+1,-1));
    // memset(dp,-1,sizeof(dp));
    cout<<1LL*m*rec(1,k,dp)%mod<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
