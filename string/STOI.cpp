// https://www.learning.algozenith.com/problems/STOI-580

/*

Description

You need to answer t test cases. In each case, your program should take in a string s and convert it into an integer. If the string is not valid print ‘Invalid’. Do not use built-in functions.


Input Format

The first line contains a single integer t denoting the number of test cases. Then t lines follow.
Each line contains a string s which you need to convert into an integer or report that the string is invalid.


Output Format

Print the integer or print ‘Invalid’.


Constraints

1 <= t <= 1000
1 <= |s| <= 18
|s| = length of the string

Sample Input 1

4
745612
-12
+13
524a2

Sample Output 1

745612
-12
13
Invalid

Note

In the first two cases, the string is converted into the corresponding integer. Note that the integer can be negative.
The third test case is not a valid string so we print Invalid.

*/


#include <bits/stdc++.h>
using namespace std;

struct Response
{
    bool isValid;
    long long int integer;

    Response() : isValid(true), integer(0) {}
    Response(bool isValid, long long int integer) : isValid(isValid), integer(integer){};
};

Response STOI(string s)
{
    long long int ans=0;
    int n=s.size();
    int is_neg=(s[0]=='-');
    int i=0;
    if(s[i]=='-' || s[i]=='+'){
        i++;
        if(n==1){
            Response t=Response(0,-1);
            return t;
        }
    }
    while(i<s.size()){
        if(s[i]<'0' || s[i]>'9'){
            Response t=Response(0,-1);
            return t;
        }
        ans=ans*10+(s[i]-'0');
        i++;
    }
    if(is_neg) ans*=-1;
    Response t=Response(true,ans);
    return t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        string s;
        cin >> s;

        Response response = STOI(s);

        if (!response.isValid)
            cout << "Invalid\n";
        else
            cout << response.integer << "\n";
    }
}
