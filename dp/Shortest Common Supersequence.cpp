// https://www.learning.algozenith.com/problems/Shortest-Common-Supersequence-903

/*

Description

Given two strings 
s
t
r
1
 and 
s
t
r
2
, return the shortest string that has both 
s
t
r
1
 and 
s
t
r
2
 as subsequences. If there are multiple valid strings, return any of them.

A string 
s
 is a subsequence of string 
t
 if deleting some number of characters from 
t
 (possibly 
0
) results in the string 
s
.


Input Format

Given function string ShortestCommonSupersequence( string &str1, string &str2) with string 
s
t
r
1
 and 
s
t
r
2
 as input.


Output Format

Complete the given function string ShortestCommonSupersequence( string &str1, string &str2) and return the shortest common supersequence of the 
2
 input strings. If there are multiple valid strings, return any of them.


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
t
r
1
|
≤
1000

1
≤
|
s
t
r
2
|
≤
1000

Sample Input 1

4
algozenith az
zzzzz zzzz
abc caba
abc xyz

Sample Output 1

algozenith
zzzzz
cabac
xyzabc

*/



int dp[1001][1001];
string s1, s2;
int rec(int i, int j) {
    if (i == s1.size() || j == s2.size())return 0;
    auto &ans = dp[i][j];
    if (ans != -1)return ans;
    ans = max(rec(i + 1, j), rec(i, j + 1));
    if (s1[i] == s2[j])ans = max(ans, 1 + rec(i + 1, j + 1));
    return ans;
}
string ShortestCommonSupersequence(string &str1, string &str2) {
    s1 = str1, s2 = str2;
    memset(dp, -1, sizeof(dp));
    string ans;
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[j]) {
            ans.push_back(s1[i]);
            i++;
            j++;
        }
        else {
            if (rec(i + 1, j) > rec(i, j + 1)) {
                ans.push_back(s1[i]);
                i++;
            }
            else {
                ans.push_back(s2[j]);
                j++;
            }
        }
    }
    while (i < s1.size())ans.push_back(s1[i++]);
    while (j < s2.size())ans.push_back(s2[j++]);
    return ans;
}
