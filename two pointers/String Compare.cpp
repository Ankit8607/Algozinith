// https://www.learning.algozenith.com/problems/String-Compare-620

/*

Description

Alice and Bob have a keyboard that can type lower case English alphabets. The keyboard also has a backspace key. When the backspace key is pressed, the last character from the string is removed and if the string is empty, nothing happens.
Alice and Bob have both typed a string in their respective computers with this keyboard. When they pressed the backspace key, ‘#’ was inserted into the string.
They want to know whether their strings are equal when it is typed into a text editor.

For example,
When the string “aab#a” is typed into a text editor, we obtain “aaa”.


Input Format

Implement the StringCompare function that takes in the two strings s and t.


Output Format

Return true if the two strings are equal and false otherwise.


Constraints

1 <= |s| <= 100000
1 <= |t| <= 100000

Sample Input 1

a##b
#a#b

Sample Output 1

Yes

Sample Input 2

a##b
#a#c

Sample Output 2

No

Note

Both strings become “b” in the text editor.
String s becomes  “b” while the string t becomes “c”.

*/


// #include <bits/stdc++.h>
// using namespace std;

// bool StringCompare(string s, string t) {
// 	string a="",b="";
//     int cnt=0;
//     int n=s.length();
//     for(int i=n-1; i>=0; i--) {
//         if(s[i]=='#') cnt++;
//         else if(cnt) cnt--;
//         else a+=s[i];
//     }
//     reverse(a.begin(), a.end());

//     n=t.size();
//     cnt=0;
//     for(int i=n-1; i>=0; i--){
//         if(t[i]=='#') cnt++;
//         else if(cnt) cnt--;
//         else b+=t[i];
//     }
//     reverse(b.begin(),b.end());

//     return a==b;
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	string s, t;
// 	cin >> s >> t;
// 	if (StringCompare(s, t))
// 		cout << "Yes";
// 	else
// 		cout << "No";
// }


//  Using two pointers

bool StringCompare(string s, string t) {
    int i = (int)s.length() - 1;
    int j = (int)t.length() - 1;
    int skips = 0;
    int skipt = 0;
    while (i >= 0 || j >= 0) {
        while (i >= 0) {
            if (s[i] == '#') {
                skips++;
                i--;
            }
            else if (skips > 0) {
                skips--;
                i--;
            }
            else
                break;
        }
        while (j >= 0) {
            if (t[j] == '#') {
                skipt++;
                j--;
            }
            else if (skipt > 0) {
                skipt--;
                j--;
            }
            else
                break;
        }
        if (i >= 0 && j >= 0 && s[i] != t[j])
            return false;
        if ((i >= 0) != (j >= 0))
            return false;
        i--;
        j--;
    }
    return true;
}
