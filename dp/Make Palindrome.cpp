// https://www.learning.algozenith.com/problems/Make-Palindrome-904

/*

Description

Given a string 
s
, find the minimum number of characters that need to be inserted into the string to make it a palindrome.


Input Format

First line contains 
T
 - the number of test cases.
First line of each test case contains the string 
s
.


Output Format

For each test case, output the minimum number of characters that need to be inserted into the string to make it a palindrome.


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
|
≤
1000

Sample Input 1

4
algozenith
abba
goomgle
fft

Sample Output 1

9
0
3
1

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

string s;
int dp[1010][1010];

int rec(int l,int r){
    if(l>=r) return 0;

    if(dp[l][r]!=-1) return dp[l][r];

    int ans=1e9;
    if(s[l]==s[r]) ans=rec(l+1,r-1);
    else ans=min(ans,1+min(rec(l+1,r),rec(l,r-1)));

    return dp[l][r]=ans;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>s;
    cout<<rec(0,s.size()-1)<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
