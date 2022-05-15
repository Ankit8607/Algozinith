// link: https://www.learning.algozenith.com/problems/Closest-Points-530

/*

Description

Given coordinates of the N points, find the K closest point to the origin. Print the points in order - 

The closest point to the origin first.
If the distance is the same, then one with the smallest ‘X coordinate.

Input Format

The first line contains two space-separated integers N, K (1 ≤ K ≤ N ≤ 10^6).

The next N lines contain Coordinates of the points (1 ≤ X, Y ≤ 10^5).

Try to do it in NlogK. In the actual interview after NlogN solution, you will have to optimize it further to NlogK solution.


Output Format

Print K closest points in the order mentioned in the statement.


Sample Input 1

5 3
1 5
7 8
8 1
1 6
2 4

Sample Output 1

2 4
1 5
1 6


*/



#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k; cin >> n >> k;
    priority_queue<pair<int, pair<int, int>>> pq;
    for(int i = 0; i < n; i ++) {
        int x, y; cin >> x >> y;
        pq.push({x * x + y * y, {x, y}});
        if(pq.size() > k) pq.pop();
    }

    vector<pair<int, int>> ans;
    while(!pq.empty()) {
        ans.push_back({pq.top().second.first, pq.top().second.second});
        pq.pop();
    }

    reverse(ans.begin(), ans.end());
    for(auto p : ans) {
        cout << p.first << " " << p.second << '\n';
    }
}   

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
