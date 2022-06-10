// https://www.learning.algozenith.com/problems/SLICES-II-613

/*

Description

An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences, whereas [1,2,4,5] is not an arithmetic sequence.

Given an integer array A, print the number of arithmetic subsequences of A. Since this number can be large print it modulo 109+7.

A subsequence of any array can be formed by deleting several, possibly none, elements from the array.


Input Format

The first line contains a single integer N -  the size of the array.
The second line contains N integers - the elements of the array.


Output Format

Print the number of arithmetic subsequences of A modulo 109+7.


Constraints

1 ≤  N ≤ 103

-106 ≤ A[i] ≤ 106


Sample Input 1

5
2 4 6 8 10

Sample Output 1

7

Note

All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]

*/


#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

long long findArithmeticSeq(int a[], int n)
{
    unordered_map<int, int> cnt[n];
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            long long diff=a[i]-a[j];
            if(cnt[j].find(diff)!=cnt[j].end()){
                (cnt[i][diff]+=cnt[j][diff])%=mod;
                (ans+=cnt[j][diff])%=mod;
            }
            (cnt[i][diff]+=1)%=mod;
        }
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << findArithmeticSeq(a, n) << '\n';
    return 0;
}
