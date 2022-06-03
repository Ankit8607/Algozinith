// https://www.learning.algozenith.com/problems/ONLYREP-566

/*

Description

You are given an array A of size N, consisting of elements between 1 and N-1, in random order, with only one number being repeated. Find this number.

Try to solve this using O(1) extra space.


Input Format

The first line contains an integer N - the size of the array A.
The next line contains N integers the elements of the array A.


Output Format

Print the repeated number.


Constraints

2 ≤ N ≤ 106
1 ≤ A[i] ≤ N - 1


Sample Input 1

5
3 1 2 4 2

Sample Output 1

2

Note

2 is the only number repeated in the array.

*/


#include <bits/stdc++.h>
using namespace std;

int FindRepeated(vector<int> &a)
{
    int ans=a[0];
    for(int i=1;i<a.size();i++) ans^=a[i]^i;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << FindRepeated(a) << "\n";
}
