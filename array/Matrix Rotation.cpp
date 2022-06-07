// https://www.learning.algozenith.com/problems/Matrix-Rotation-587

/*

Description

You are given an n x n 2-D matrix as input. You need to rotate the matrix 90 degrees in the clockwise direction. Print the resultant matrix.
Try to do the rotation in place, i.e, in constant extra space.


Input Format

The first line of input contains the length of the grid n. Then n lines follow, each line containing n spaced integers representing the input matrix.


Output Format

Print the resultant matrix obtained by rotating the given matrix.


Constraints

1 <= n <= 1000
-1000 <= v[i][j] <= 1000

Sample Input 1

3
1 2 3
4 5 6
7 8 9

Sample Output 1

7 4 1
8 5 2
9 6 3

Note

We rotate the input matrix by 90 degrees in the clockwise direction.

*/


#include <bits/stdc++.h>
using namespace std;

void RotateMatrix(vector<vector<int>> &v)
{
    int n=v.size();
    for(int i=0; i<n/2; i++){
        for(int j=i;j<n-i-1;j++){
            int t=v[i][j];
            v[i][j]=v[n-j-1][i];
            v[n-j-1][i]=v[n-i-1][n-j-1];
            v[n-i-1][n-j-1]=v[j][n-i-1];
            v[j][n-i-1]=t;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }

    RotateMatrix(v);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
}
