// https://www.learning.algozenith.com/problems/Interleaved-Strings-578

/*

Description

You are given three strings X, Y, and Z. You need to determine if string Z is an interleaving of X and Y. String Z is said to be interleaving X and Y if all the characters of X and Y are present in Z and the order of characters in the individual strings is preserved.
See the sample explanation for more details.


Input Format

The first line of input contains the string X.
The second line of input contains the string Y.
The third line of input contains the string Z.


Output Format

Print ‘Yes’ is the string Z is an interleaving of X and Y, and ‘No’ otherwise.


Constraints

1 <= n <= 1000 (length of X)
1 <= m <= 1000 (length of Y)
Length of Z = n + m

Sample Input 1

A
AB
BAA

Sample Output 1

No

Sample Input 2

ACA
DAS
DAACSA

Sample Output 2

Yes

Note

The order of characters is not maintained.
DAACSA
The characters in bold are from string Y and the others are from string X. The order is maintained so Z is an interleaving of X and Y.

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

string a,b,c;
int dp[1001][1001];

bool rec(int i,int j){
    if(i==a.size() and j==b.size()) return 1;

    int &ans=dp[i][j];
    if(ans!=-1) return ans;

    ans=0;
    if(a[i]==c[i+j]) 
        ans|=rec(i+1,j);
    if(b[j]==c[i+j]) 
        ans|=rec(i,j+1);
    return ans;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>a>>b>>c;
    if(rec(0,0)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

signed main(){
    IOS
    // int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
