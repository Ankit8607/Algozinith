// https://www.learning.algozenith.com/problems/LCS-of-3-Strings-900

/*

Description

Given 
3
 strings 
s
1
, 
s
2
 and 
s
3
, the task is to find the length of the longest common sub-sequence in all three given strings.


Input Format

First-line contains 
T
 - the number of test cases.
Each test case contains 
3
 strings in a single line.


Output Format

For each test case, print the length of the longest common subsequence in all the 
3
 given strings, in a new line.


Constraints

1
≤
T
≤
100

1
≤
|
s
1
|
≤
100

1
≤
|
s
2
|
≤
100

1
≤
|
s
3
|
≤
100

Sample Input 1

3
abc abc bbc
algozenith algo algorithm
algo zenith zen

Sample Output 1

2
4
0

*/


#include<bits/stdc++.h>
using namespace std;
const int mod= 10000007;
#define endl "\n"
#define F first
#define S second
#define vi vector<int>
#define ii pair<int,int>
#define all(a) a.begin(),a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define tracearray(arr,n)  cout<<#arr<<endl;for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;

int dp[101][101][101];
string a,b,c; 

int rec(int i,int j,int k){
    if(i==a.size() || j==b.size() || k==c.size()) return 0;

    int &ans=dp[i][j][k];
    if(ans!=-1) return ans;

    ans=0;
    if(a[i]==b[j] and a[i]==c[k]) ans+=1+rec(i+1,j+1,k+1);
    else{
        ans=max(ans,rec(i+1,j,k));
        ans=max(ans,rec(i,j+1,k));
        ans=max(ans,rec(i,j,k+1));
    }

    return ans;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>a>>b>>c;
    cout<<rec(0,0,0)<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
