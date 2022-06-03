// https://www.learning.algozenith.com/problems/Combination-Sum-I-852

/*

Description

Given a vector of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from vector candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.


Input Format

Complete the function combinationSum(candidates, target). 


Output Format

return combinations as vector<vector<int>> in any order.


Constraints

1 ≤ candidates.length() ≤ 30.
1 ≤ candidates[i] ≤ 200.
All elements of candidates are distinct.
1 ≤ target ≤ 500.

Sample Input 1

candidates = [2,3,6,7], target = 7

Sample Output 1

[[2,2,3],[7]]

Sample Input 2

candidates = [2], target = 1

Sample Output 2

[]

*/



#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

vector<vector<int>>ans;
vector<int>tmp;

void rec(int level,vector<int>& candidates, int tar){
    if(level==candidates.size()){
        if(tar==0) ans.push_back(tmp);
        return;
    }

    rec(level+1,candidates,tar);
    if(tar>=candidates[level]){
        tmp.push_back(candidates[level]);
        rec(level,candidates,tar-candidates[level]);
        tmp.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    rec(0,candidates,target);
    return ans;
}




void checker() {
    int n, x, target;
    cin >> n >> target;
    vector<int> t;
    for (int i = 0; i < n; i++) {
        cin >> x;
        t.push_back(x);
    }
    auto v = combinationSum(t, target);
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
