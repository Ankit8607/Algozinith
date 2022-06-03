// https://www.learning.algozenith.com/problems/Combination-Sum-II-853

/*

Description

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.


Input Format

Complete the function combinationSum(k, n).


Output Format

Return a list ( vector<vector<int>> ) of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.


Constraints

2 ≤ k ≤ 9
1 ≤ n ≤ 60

Sample Input 1

k = 3, n = 9

Sample Output 1

[[1,2,6],[1,3,5],[2,3,4]]

Sample Input 2

k = 4, n = 1

Sample Output 2

[]

Sample Input 3

k = 9, n = 45

Sample Output 3

[[1,2,3,4,5,6,7,8,9]]

*/


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

vector<vector<int>>ans;
vector<int>tmp;

void rec(int k,int n,int st){
    if(n==0 and k==0){
        ans.push_back(tmp);
        return;
    }
    if(st==10 || k==0 || n==0) return;

    rec(k,n,st+1);
    if(st<=n){
        tmp.push_back(st);
        rec(k-1,n-st,st+1);
        tmp.pop_back();
    }
    return;
}
vector<vector<int>> combinationSum(int k, int n) {
    rec(k,n,1);
    return ans;
}




void checker() {
    int k, n;
    cin >> k >> n;
    vector<int> t;
    auto v = combinationSum(k, n);
    for (auto &x : v) {
        sort(x.begin(), x.end());
    }
    sort(v.begin(), v.end());
    for (auto x : v) {
        for (auto y : x)cout << y << " ";
        cout << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        checker();
        // i++;
    }
    return 0;
}
