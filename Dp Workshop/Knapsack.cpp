// https://www.learning.algozenith.com/problems/Knapsack-714

/*

Description

There are N items numbered from 1 to N. The ith item has a weight of wi and a value of vi.

You have to choose some items out of the N items and carry them home in a knapsack. The capacity of the knapsack is W which donate the maximum weight that can be carried inside the knapsack. In other words, W means the total summation of all weights of items that can be carried in the knapsack.

Print maximum possible sum of values of items that you can take home.

Note: Solve this problem using recursion.


Input Format

First line contains two numbers N and W number of items and the capacity of the knapsack.

Next N lines will contain two numbers wi and vi .


Output Format

Print maximum possible sum of values of items that you can take home.


Constraints

(1≤N≤20,1≤W≤100)

(1≤wi≤50,1≤vi≤1000)


Sample Input 1

3 8
3 30
4 50
5 60

Sample Output 1

90

Sample Input 2

6 15
6 5
5 6
6 4
6 6
3 5
7 2

Sample Output 2

17

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

int dp[21][1011];
vector<ii>arr;

int rec(int level,int sum){
    if(sum<0) return -1e9;
    if(level==arr.size()) return 0;

    if(dp[level][sum]!=-1) return dp[level][sum];

    return dp[level][sum]=max(rec(level+1,sum),arr[level].second+rec(level+1,sum-arr[level].first));
}

void solve(){
    int n,w;
    cin>>n>>w;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,w)<<endl;
}

signed main(){
    IOS
    // int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
