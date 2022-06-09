// https://www.learning.algozenith.com/problems/Minimum-Swaps-Palindrome-978

/*

Description

Given a lowercase alphabet string 
s
, output the minimum number of adjacent swaps required to convert it into a palindrome. If it's not possible, output 
−
1
.


Input Format

The first line contains 
T
 - the number of test cases.
The first line of each test case contains string 
s
.


Output Format

For each test case, output the minimum number of adjacent swaps required to convert it into a palindrome. If it's not possible, then output 
−
1
.


Constraints

1
≤
T
≤
100

1
≤
|
s
|
≤
1000

Sample Input 1

4
daamm
baa
abba
algozenith

Sample Output 1

4
1
0
-1

*/


#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'


int minswaps(string s) {
    int l = 0, r = s.size() - 1, ans = 0, odd = 0;
    vector<int> cnt(26, 0);
    for (auto c : s)cnt[c - 'a']++;
    for (int i = 0; i < 26; i++)odd += (cnt[i] & 1);
    if (odd > 1)return -1;
    while (l < r) {
        int i = l, j = r;
        while (s[i] != s[j])j--;
        if (i == j) {
            swap(s[i], s[i + 1]), ans++;
            continue;
        }
        while (j < r)swap(s[j], s[j + 1]), j++, ans++;
        l++, r--;
    }
    return ans;
}


void solve() {
    string s; cin >> s;
    cout << minswaps(s) << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
