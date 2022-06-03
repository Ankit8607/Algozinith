// https://www.learning.algozenith.com/problems/Bilkul-ricks-nhi-lena-ka-794

/*

Description

Baburao Ganpatrao Apte a.k.a “Babu Bhaiya” created a new strong password for his locker, to save his money from Raju, who is promising to double his money in 21 days! :P

The new password z is a positive integer of at most 19 digits. Babu Bhaiya is bad at remembering passwords and doesn't want to take risks ( as he says “ bilkul ricks nhi lena ka ” ), so he divided his integer password into 2 positive integers a and b, such that z = a + b, and wrote down a&b and a|b values in his diary.

As expected, he forgot his password after a few days. Help him to retrieve his password z. 

It is given that a&b should be a sub-mask of a|b.


Input Format

The input contains a single line having a&b and a|b values.


Output Format

Output a single integer z, the password. 


Constraints

z is a positive integer of at most 19 digits and less than LLONG_MAX.
a&b should be a sub-mask of a|b.

Sample Input 1

1 7

Sample Output 1

8

Note

Explanation: Since  a&b =1 and a|b = 7, then a=3 and b=5, therefore z = a + b = 8.

*/


#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    cout<<n+m<<endl;
    return 0;
}
