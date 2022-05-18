// https://www.learning.algozenith.com/problems/Matching-Patterns-597

/*

Description

You are given a string s and a pattern p. The string s consists of only lower case alphabets while the pattern can also contain ‘?’ and ‘*’.
You need to find whether the pattern can match the string when:

‘?’ - Matches any single character in s.
‘*’ - Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string.


Input Format

The first line of input contains the string s and the second line contains the pattern p.


Output Format

Print ‘Yes’ if the pattern matches the string and ‘No’ otherwise.


Constraints

0 <= n <= 1000 (length of s)
0 <= m <= 1000 (length of p)

Sample Input 1

abcde
*ab*e

Sample Output 1

Yes

Sample Input 2

abc
a?b

Sample Output 2

No

Note

First ‘*’ matches empty sequence. Second ‘*’ matches “cd”.
‘?’ matches ‘b’ but the last character is different.

*/


#include <bits/stdc++.h>
using namespace std;

bool rec(int i,int j,string &s,string &p){
    if(i==s.size() and j==p.size())return 1;
    if(i>=s.size()){
        bool ans;
        if(p[j]=='*') ans=rec(i,j+1,s,p);
        else ans=0;
        return ans;
    }
    if(j>=p.size()) return 0;
    bool ans=0;
    if(p[j]=='?'){ 
        return rec(i+1,j+1,s,p);
    }
    else if(p[j]=='*'){
        // ans=rec(i,j+1);
        // if(ans) return 1;
        for(int k=0;k<=s.size()-i;k++){
            if(rec(i+k,j+1,s,p)) return 1;
        }
        return 0;
    }
    else if(s[i]==p[j]){
        return rec(i+1,j+1,s,p);
    }
    else return 0;
}

bool isMatch(string s, string p)
{
	return rec(0,0,s,p);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, p;
	getline(cin, s);
	getline(cin, p);

	if (isMatch(s, p))
		cout << "Yes\n";
	else
		cout << "No\n";
}
