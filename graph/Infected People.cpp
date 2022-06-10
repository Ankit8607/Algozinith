// https://www.learning.algozenith.com/problems/Infected-People-568

/*

Description

Your city is having people infected with a virus. The city in which you live is represented as a grid consisting of n rows and m columns. Cells containing 2 are the cells where the people infected with the virus are present and the cells having 1 are the cells having people not yet infected with the virus. There are certain empty cells which are represented by 0. The infected people in a unit time can infect all their adjacent cells, i.e, if they are present at cell [i, j] they can infect cells [i-1, j], [i+1, j], [i, j-1] and [i, j+1]. The virus cannot pass through empty cells. Your task is to print the minimum time in which all the people are infected with the virus. If the virus cannot infect everyone, print -1.


Input Format

The first line contains two integers n and m  — the number of rows and columns, respectively.
The following n lines contain m integers each, the j-th element in the i-th line is the number written in the j-th cell of the i-th row.


Output Format

Print the minimum time in which everyone can be infected or -1 if everyone cannot be infected.


Constraints

1 <= n <= 1000
1 <= m <= 1000

Sample Input 1

3 3
0 1 2
0 1 2
1 1 2

Sample Output 1

2

Sample Input 2

3 3
0 1 2
0 1 2
1 0 2

Sample Output 2

-1

Note

After 1 unit time,
0 2 2
0 2 2
1 2 2.

Still there is a person which has not yet been infected.
0 2 2
0 2 2
2 2 2.
So the minimum time in which everyone is infected is 2.

For second test case,
After 1 unit time,
0 2 2
0 2 2
1 0 2.
No more cells can be infected.
Still there is a person which has not yet been infected.
So we print -1.

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

bool isvalid(int x,int y,int n,int m,vector<vector<int>>&arr){
    if(x>=0 and x<n and y>=0 and y<m and arr[x][y]==1 ) return 1;
    return 0;
}

void solve(){
    int n,m; cin>>n>>m;
    int cnt=0;
    vector<vector<int>>arr(n,vector<int>(m));
    queue<ii>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2) q.push({i,j});
            else if(arr[i][j]==1) cnt++;
        }
    }
    int time=0;
    while(!q.empty()){
        queue<ii>tmp;
        while(!q.empty()){
            int x=q.front().F,y=q.front().S; 
            q.pop();
            if(isvalid(x+1,y,n,m,arr)) cnt--,arr[x+1][y]=2,tmp.push({x+1,y});
            if(isvalid(x-1,y,n,m,arr)) cnt--,arr[x-1][y]=2,tmp.push({x-1,y});
            if(isvalid(x,y+1,n,m,arr)) cnt--,arr[x][y+1]=2,tmp.push({x,y+1});
            if(isvalid(x,y-1,n,m,arr)) cnt--,arr[x][y-1]=2,tmp.push({x,y-1});
        }
        if(tmp.empty()) break;
        time++;
        q=tmp;
    }
    if(cnt) cout<<-1<<endl;
    else cout<<time<<endl;
}

signed main(){
    IOS
    // int t=1; cin>>t; while(t--) 
    solve();
    return 0;
}
