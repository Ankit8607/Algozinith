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



#define ll int64_t
#define endl '\n'

const int mx = 1e5 + 10;
int n, q, dp[100][mx], a[100];
bool rec(int i, int sum) {
    if (sum < 0)return 0;
    if (i == -1) {
        if (sum == 0)return 1;
        return 0;
    }
    auto &ans = dp[i][sum];
    if (ans != -1)return ans;
    ans = (rec(i - 1, sum) | rec(i - 1, sum - a[i]));
    return ans;
}
vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    n = arr.size(), q = queries.size();
    for (int i = 0; i < n; i++)a[i] = arr[i];
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> ans;
    for (auto x : queries) {
        if (rec(n - 1, x)) {
            vector<int> t;
            int i = n - 1;
            while (x) {
                if (rec(i-1, x - a[i]))x -= a[i], t.push_back(i);
                i--;
            }
            reverse(t.begin(), t.end());
            ans.push_back(t);
        }
        else {
            ans.push_back({ -1});
        }
    }
    return ans;
}
