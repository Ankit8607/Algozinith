// https://www.learning.algozenith.com/problems/Minimum-Platforms-590

/*

Description

Through a railway station, N trains pass each having a particular arrival and departure time. Find the minimum number of platforms required such that no train is kept waiting. If a train arrives at time x and other leaves at the same time x then they cannot use the same platform.


Input Format

The first line of each test case contains a single integer N - the number of trains.
N lines follow each containing two integers s and t - the arrival and departure time of each of these trains.


Output Format

Print the minimum number of platforms required in a new line.


Constraints

1 ≤ N ≤ 105
1 ≤ s ≤ t ≤ 108


Sample Input 1

6
900 910
940 1200
950 1120
1100 1130
1500 1900
1800 2000

Sample Output 1

3

Sample Input 2

3
900 1000
1100 1200
1235 1240

Sample Output 2

1

Note

At time 1110 3 trains are present simultaneously, so 3 platforms are required to accommodate all the trains in the first test case.

*/


#include <bits/stdc++.h>
using namespace std;

int MinimumPlatforms(vector<pair<int, int>> &trains)
{
    sort(trains.begin(),trains.end());
    priority_queue<int,vector<int>,greater<int>>q;
    int cnt=0,ans=0;
    for(auto i:trains){
        while(cnt and q.top()<i.first) q.pop(),cnt--;
        q.push(i.second);
        cnt++;
        ans=max(ans,cnt);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> trains;

    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        trains.push_back({s, t});
    }

    cout << MinimumPlatforms(trains) << '\n';
}
