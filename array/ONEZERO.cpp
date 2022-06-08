// https://www.learning.algozenith.com/problems/ONEZERO-621

/*

Description

You are given an array A of binary strings, of size N, and two integers x and y.

Return the size of the largest subset of A such that there are at most x 0's and y 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.


Input Format

The first line contains 3 integers N, x, and y.
N lines follow each containing a binary string.


Output Format

Print the maximum possible size of the subset.


Constraints

1 ≤ N ≤ 100

1 ≤ x,y ≤ 100

1 ≤ length of binary string A[i] ≤ 200


Sample Input 1

5 5 3
10
0001
111001
1
0

Sample Output 1

4

Sample Input 2

3 1 1
10
0
1

Sample Output 2

2

Note

In the first test case, the largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
In the second test case, the largest subset is {"0", "1"}, so the answer is 2.

*/

#include <bits/stdc++.h>
using namespace std;

int n;
int dp[101][101][101];

int rec(int level,int x,int y,int arr[][2]){
    if(level==n) return 0;

    if(dp[level][x][y]!=-1) return dp[level][x][y];

    int ans=rec(level+1,x,y,arr);
    if(x>=arr[level][0] and y>=arr[level][1])
        ans=max(ans,1+rec(level+1,x-arr[level][0],y-arr[level][1],arr));
    
    return dp[level][x][y]=ans;
}

int findMaxSubset(vector<string> &v, int x, int y)
{
    memset(dp,-1,sizeof(dp));
    n=v.size();
    int arr[n][2];
    for(int i=0; i<n;i++){
        arr[i][0]=arr[i][1]=0;
        for(auto j:v[i]){
            if(j=='0') arr[i][0]++;
            else arr[i][1]++;
        }
    }
    return rec(0,x,y,arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    vector<string> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    cout << findMaxSubset(v, x, y) << '\n';
    return 0;
}
