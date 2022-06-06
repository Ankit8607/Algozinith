// https://www.learning.algozenith.com/problems/Tallest-Stack-575

/*

Description

There are n types of 3-D rectangular boxes. Each box has a height h, a width w and a length l. You are allowed to rotate the boxes so that any side can function as its base. Your task is to create the tallest stack by stacking the boxes on top of each other but you are allowed to stack a box on top of the other only if the dimensions of the 2-D base of the lower box are strictly larger than those of the higher box, i.e, you can stack a box with dimensions {h1, w1, l1} on top of another box with dimensions {h2, w2, l2} only if h1 < h2 and w1 < w2. You are also allowed to use multiple instances of the same box. 
You need to print the height of the tallest possible stack that follows the above conditions.


Input Format

The first line contains a single integer n.
Then n lines follow. The ith line contains three space-separated integers denoting the height, width, and length of the ith box respectively.


Output Format

Print the height of the tallest stack possible.


Constraints

1 <= n <= 1000
1 <= h,w,l <= 1000

Sample Input 1

4
2 6 4
1 2 3
15 7 8
8 2 3

Sample Output 1

35

Note

One of the optimal ways is:

(15, 8, 7) -> (8, 7, 15) -> (6, 4, 2) -> (3, 2, 8) -> (2, 1, 3)
Therefore height of the stack = 7+15+2+8+3
                = 35.
We can see that the dimensions of the base are strictly decreasing.
No other combination of boxes produces height greater than this.

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 998244353;
const int N=2000010;
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define pb push_back
#define ii pair<int,int>
#define all(a) a.begin(),a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define tracearray(arr,n)  cout<<#arr<<endl;for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;

int n;
vector<pair<ii,int>>arr;
int dp[6010][6010];

int rec(int level,int last){
    if(level==6*n) return 0;
    if(last!=-1 and dp[level][last]!=-1) return dp[level][last];

    int ans=rec(level+1,last);
    if(last==-1) ans=max(ans,arr[level].S+rec(level+1,level));
    else if(arr[last].F.F>arr[level].F.F and arr[last].F.S>arr[level].F.S){
        ans=max(ans,arr[level].S+rec(level+1,level));
    }
    
    return dp[level][last]=ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        int h,w,l; cin>>h>>w>>l;
        arr.pb({{h, w}, l});
        arr.pb({{w, h}, l});
        arr.pb({{h, l}, w});
        arr.pb({{l, h}, w});
        arr.pb({{w, l}, h});
        arr.pb({{l, w}, h});
    }
    sort(arr.rbegin(),arr.rend());
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,-1)<<endl;
}
