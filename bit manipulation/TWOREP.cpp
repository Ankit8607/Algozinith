// https://www.learning.algozenith.com/problems/TWOREP-567

/*

Description

You are given an array of size 2N + 2 where N elements occur twice and 2 occur just once. You have to find the 2 non-repeating elements.

Try to solve this using O(1) extra space.


Input Format

The first line contains a single integer N.
The second line contains 2N + 2 integers - the array elements.


Output Format

Print two integers - the elements which are not repeated in ascending order.


Constraints

0 ≤ N ≤ 5 x 105

1 ≤ A[i] ≤ N + 2


Sample Input 1

4
1 2 3 4 1 4 2 3 5 6

Sample Output 1

5 6

Note

5 and 6 are the numbers that are not repeated

*/


#include <bits/stdc++.h>
using namespace std;

vector<int> FindRepeated(vector<int> &a)
{
    int xo=0;
    for(auto i:a) xo^=i;
    int onbit;
    for(int i=0;i<32;i++){
        if(xo&(1<<i)){
            onbit=i;
            break;
        }
    }
    int num1=0,num2=0;
    for(auto i:a){
        if(i&(1<<onbit)) num2^=i;
        else num1^=i;
    }
    if(num1>num2) return {num2,num1};
    return {num1,num2};
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(2 * n + 2);

    for (int i = 0; i < 2 * n + 2; i++)
        cin >> a[i];

    vector<int> ans = FindRepeated(a);
    cout << ans[0] << " " << ans[1] << "\n";
}
