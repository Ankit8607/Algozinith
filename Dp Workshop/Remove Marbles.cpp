// https://www.learning.algozenith.com/problems/Remove-Marbles-249

/*

Description

You are given N marbles in different colours. You have to remove marbles till there are no marbles left. Each time you can choose continuous marbles with the same color, remove them and get k*k points (where ‘k’ is the length of the continuous marbles removed). Find the maximum points you can get.


Input Format

The first line contains one integer N - the length of the array. 

The second line contains N space-separated integers - the colours of the marbles.


Output Format

Print the maximum points you can get in a new line.


Constraints

1 ≤ N ≤ 100

0 ≤ Ai ≤ 100


Sample Input 1

4
2 1 3 2

Sample Output 1

6

Sample Input 2

6
4 3 1 1 4 2

Sample Output 2

10

Note

For the first test case of the example, remove 1, then 3 and then 2, we get 1*1+1*1+2*2 = 6.

For the second test case of the example, remove 1, then 3, then 4 and 2, we get 2*2+1*1+2*2+1*1 = 10.

*/


#include<bits/stdc++.h>
using namespace std;

int n;
int arr[101];
int dp[101][101][101];

int rec(int l,int r,int x){
    if(l>r) return 0;
    if(l==r) return (x+1)*(x+1);
    if(dp[l][r][x]==-1){
        int ans = (x+1)*(x+1)+rec(l+1,r,0);
        for(int i=l+1;i<=r;i++){
            if(arr[i]==arr[l])
                ans=max(ans,rec(i,r,x+1)+rec(l+1,i-1,0));
        }
        dp[l][r][x]=ans;
    }
    return dp[l][r][x];
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1,0)<<endl;
}    

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int _t;cin>>_t;while(_t--)
    solve();
}
