// https://www.learning.algozenith.com/problems/MATMED-569

/*

Description

Given a row wise sorted matrix A of size N x M, where N and M are always odd, find the median of the matrix.


Input Format

The first line of each test case contains two integers N and M - the dimensions of the matrix.
The next N lines contain M integers - the elements of the matrix A.


Output Format

Print the median of the matrix.


Constraints

1 ≤ N,M ≤ 1000
1 ≤ A[i] ≤ 106


Sample Input 1

3 1
3
2
1
 


Sample Output 1

2


Sample Input 2

3 3
1 2 2
1 3 5
4 5 5


Sample Output 2

3


Note

Sorting all the matrix elements gives us [1,2,3] in the first test case.
Sorting all the matrix elements gives us [1,1,2,2,3,4,5,5,5] in the second test case.

*/


#include <bits/stdc++.h>
using namespace std;

int MedianInMatrix(vector<vector<int>> &a)
{
    int n=a.size(),m=a[0].size();
    int lo=1,hi=1e6,tot=n*m;
    int ans=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        int cnt=0;
        for(int i=0;i<n;i++)
            cnt+=upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
        if(cnt<=(tot/2)) lo=mid+1;
        else hi=mid-1,ans=mid;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    cout << MedianInMatrix(a) << "\n";

    return 0;
}
