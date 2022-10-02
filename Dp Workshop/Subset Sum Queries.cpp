// https://www.learning.algozenith.com/problems/Subset-Sum-Queries-897

/*

Description

Given an array of size 
N
, and 
Q
 queries, for each query, you need to get the indices of the elements of the array whose subset-sum is equal to the queried sum 
s
u
m
i
, if possible, else return 
−
1
.


Input Format

Complete the Function subset_queries( vector &arr, vector &queries ) that takes vector 
a
 and 
q
u
e
r
i
e
s
 vector as input.


Output Format

Return a vector < vector < int > > having 
0
-based indices of the elements of the array whose subset-sum is equal to the queried sum 
s
u
m
i
 for each 
i
t
h
 query, if possible, else return vector { 
−
1
 }.


Constraints

1
≤
N
≤
100
 , size of vector < int > arr
1
≤
Q
≤
10
5
 , size of vector < int > queries
1
≤
a
r
r
[
i
]
≤
10
5

1
≤
s
u
m
i
≤
10
5

Sample Input 1

arr[] = { 1, 2, 3, 4, 5 }
queries[]= { 7, 16, 3 }

Sample Output 1

{ {1, 4}, {-1}, {2} }

*/


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'
int dp[101][100010];

bool rec(int level,int sum,vector<int>&arr){
    if(sum==0) return 1;
    if(sum<0) return 0;
    if(level==arr.size()) return 0;

    if(dp[level][sum]!=-1) return dp[level][sum];

    return dp[level][sum]=rec(level+1,sum-arr[level],arr)|rec(level+1,sum,arr);

}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    memset(dp,-1,sizeof(dp));
    vector<vector<int>>ans;
    for(int i=0;i<queries.size();i++){
        vector<int>res;
        if(rec(0,queries[i],arr)){
            int sum=queries[i];
            for(int j=0;j<arr.size();j++){
                if(rec(j+1,sum-arr[j],arr)) res.push_back(j), sum-=arr[j];
            }
            ans.push_back(res);
        }
        else ans.push_back({-1});
    }
    return ans;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
