// https://www.learning.algozenith.com/problems/Grid-Queries-565

/*

Description

You are given a grid consisting of n rows and m columns. In the given grid, it is guaranteed that all the rows are sorted in increasing order and the columns are also sorted in increasing order. You have to answer q queries. In each query you are given a number x. You need to print ‘Yes’ if the number is present in the grid and ‘No’ otherwise.

Try to solve this problem using constant extra space.


Input Format

The first line contains two integers n and m — the number of rows and columns, respectively.
The following n lines contain m integers each, the j-th element in the i-th line is the number written in the j-th cell of the i-th row.
The next line contains a single integer q - the number of queries.
Then q lines follow. The ith line contains the value of x for the ith query.


Output Format

Print q lines. For each query print ‘Yes’ if the number is present in the grid and ‘No’ otherwise.


Constraints

1 <= n,m <= 1000
1 <= q <= 10000
1 <= grid[i][j] <= 109
1 <= x <= 106


Sample Input 1

3 4
1 3 4 6
2 5 7 9
7 11 12 19
5
3
8
10
12
13

Sample Output 1

Yes
No
No
Yes
No

Note

Yes’ is printed for the numbers present in the grid and ‘No’ for the numbers not present.

*/


#include <bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>> &grid, int x)
{
    int n = (int)grid.size();
    int m = (int)grid[0].size();
    int i, j;
    i = 0;
    j = m - 1;
    while (i < n && j >= 0)
    {
        if (grid[i][j] == x) // value found
            return true;
        if (grid[i][j] > x) // eliminating this column
            j--;
        else // eliminating this row
            i++;
    }
    return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> grid(n, vector<int>(m));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];
	}
	
	int q;
	cin >> q;
	
	while (q--)
	{
		int x;
		cin >> x;
		if (search(grid, x))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
