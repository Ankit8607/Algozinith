// https://www.learning.algozenith.com/problems/String-Compression-576

/*

Description

You manage a database consisting of huge strings. Each string in the database has an associated id which is an integer. You need to generate a compressed string using the id of the string in the database.
The strings can consist of:

A lower case alphabet [‘a’ to ‘z’] - total 26 characters.
An upper case alphabet [‘A’ to ‘Z’] - total 26 characters.
A digit [‘0’ to ‘9’] - total 10 characters.
So there are a total of 62 possible characters.
Your task is to convert the integer (id of the string) to a 62 base number where digits of the 62 base are:

0-25 → ‘a’ to ‘z’
26-51 → ‘A’ to ‘Z’
52-61 → ‘0’ to ‘9’.

Input Format

The only line of input contains a single integer n which is the id associated with the string you want to compress.


Output Format

You need to output the compressed string which is the representation of the integer n in base 62.


Constraints

1 <= n <= 1018


Sample Input 1

54321


Sample Output 1

oij


Sample Input 2

1071819


Sample Output 2

eEZz


Note

1) ‘o’ * 622 + ‘i’ * 62 + j = 54321

*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n; cin>>n;
    string ans="";
    while(n){
        int t=n%62;
        if(t<26) ans+=t+'a';
        else if(t<52) ans+=t-26+'A';
        else ans+=t-52+'0';
        n/=62;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
