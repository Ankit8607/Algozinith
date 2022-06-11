// https://www.learning.algozenith.com/problems/Course-Scheduling-617

/*

Description

There are a total of n courses that you can take. The courses are labeled from 0 to n-1.
You are also given a prerequisites array where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

For example, the pair [1, 2] indicates that in order to take course 2 you have to first take course 1.

You have to determine if you can finish all the courses following all the prerequisites given.


Input Format

The first line contains two space-separated integers n and m - the total number of courses and the number of prerequisites.
Then m lines follow. The i-th line contains a pair of integers denoting the i-th prerequisite.


Output Format

Print ‘Yes’ if you can finish all the courses and ‘No’ otherwise.


Constraints

1 <= n <= 100000
0 <= m <= min(100000, n(n-1)/2)
0 <= ai,bi < n
Each pair (a, b) is distinct.

Sample Input 1

3 3
0 1
1 2
0 2

Sample Output 1

Yes

Sample Input 2

2 2
0 1
1 0

Sample Output 2

No

Note

We can take the courses in the following order : 0 1 2.
All prerequisites are followed.
Course 0 needs course 1 as a prerequisite whereas course 1 needs course 0 as a prerequisite which is not possible.

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

int n,m;
vector<vector<int>>g;
vector<int>vis;
bool is_cycle=0;

void dfs(int node){
    vis[node]=1;
    for(auto i:g[node]){
        vis[node]=2;
        if(vis[i]==2){
            is_cycle=1;
            return;
        }
        if(vis[i]==0)dfs(i);
        vis[node]=1;
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n);
    vis.resize(n,0);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i);
    }
    if(is_cycle) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}

signed main(){
    IOS
    // int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
