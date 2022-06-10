// https://www.learning.algozenith.com/problems/SLICES-I-612

/*

Description

An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences, whereas [1,2,4,5] is not an arithmetic sequence.

Given an integer array A, return the number of arithmetic subarrays of A.

A subarray of any array can be formed by deleting several, possibly none, elements from either end of the array.


Input Format

The first line contains a single integer N -  the size of the array.
The second line contains N integers - the elements of the array.


Output Format

Print the number of arithmetic subarrays of A.


Constraints

1 ≤  N ≤ 105

-109 ≤ A[i] ≤ 109


Sample Input 1

4
1 3 5 7

Sample Output 1

3

Sample Input 2

4
1 2 3 5

Sample Output 2

1

Sample Input 3

3
1 0 1

Sample Output 3

0

Note

[1,3,5] [3,5,7] and [1,3,5,7] are the arithmetic sequences in the first test case.

[1,2,3] is the only arithmetic sequence in the second test case.

No arithmetic sequence in the third test case.

*/



#include <bits/stdc++.h>
using namespace std;

long long findArithmeticSeq(int a[], int n)
{
    if(n<=2) return 0;
    long long ans=0,last=a[1]-a[0];
    int i=2;
    while(i<n){
        int cnt=0;
        while(i<n and a[i]-a[i-1]==last){
            cnt++;i++;
            ans+=cnt;
        }
        if(i<n)
            last=a[i]-a[i-1];
        i++;
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
