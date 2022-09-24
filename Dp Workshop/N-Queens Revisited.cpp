// https://www.learning.algozenith.com/problems/N-Queens-Revisited-137

/*

Description

An S-Queen is a chess piece that combines the power of a knight and a queen. 
Find the number of ways to place N S-Queens on N x N chessboard.



Input Format

The input contains only single integer N denoting the side of the chessboard. 


Output Format

Print the number of ways to place N S-Queens on the N x N chessboard.


Constraints

2 ≤ N ≤ 14


Sample Input 1

3

Sample Output 1

0

Sample Input 2

10

Sample Output 2

4

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=13;
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int power(int a, int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;     
}
int fact[N];
void fac(){
    fact[0]=1;
    for(int i=1;i<=N;i++) 
        fact[i]=(i*fact[i-1])%mod;
}
vector<int>v;
map<int,int>mp;
int ans=0,n;
char store[14][14];
bool check(int row,int col){
    for(int prow=0;prow<row;prow++){
        int pcol=v[prow];
        if(pcol==col||(abs(pcol-col)==abs(prow-row)))
            return 0;
        if(prow+1==row){
            if(abs(pcol-col)==2) return 0;
        }
        if(prow+2==row){
            if(abs(pcol-col)==1) return 0;
        }
    }
    return 1;
}
void rec(int level){
    if(level==n){
        ans++;
        return;
    }
    for(int col=0;col<n;col++){
        if(check(level,col)){
            v.push_back(col);
            rec(level+1);
            v.pop_back();
        }
    }
}
void solve(){
    cin>>n;
    rec(0);
    cout<<ans<<endl;
}

signed main(){
    IOS
    int t=1;
    // cin>>t;
    // fac();
    while(t--) solve();
    return 0;
}
