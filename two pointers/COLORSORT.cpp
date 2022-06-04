// https://www.learning.algozenith.com/problems/COLORSORT-608

/*

Description

Sort an array A, of size N, containing only 0, 1, 2 as elements. Can you sort them in-place?


Input Format

The first line contains a single integer N - the size of the array.
The second line contains N integers - the elements of the array.


Output Format

Print the sorted array.


Constraints

1 ≤ N ≤ 106
0 ≤ A[i] ≤ 2


Sample Input 1

6
2 0 1 0 1 2

Sample Output 1

0 0 1 1 2 2

*/


#include <bits/stdc++.h>
using namespace std;

void sort(int a[], int n)
{
    int i=0,j=n-1,cur=0;
    while(cur<=j){
        if(a[cur]==2){
            swap(a[j--],a[cur]);
        }
        else if(a[cur]==0){
            swap(a[i],a[cur]);
            i++,cur++;
        }
        else cur++;
    }
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
    sort(a, n);
    for (int i : a)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
