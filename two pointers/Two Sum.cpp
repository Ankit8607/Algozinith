// Link: https://www.learning.algozenith.com/problems/Two-Sum-529

/*

Description

Given an array A of N integers and a target integer S. Find if there exist two index i, j such that A[i]+A[j]=S, i≠j.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 100000)

The first line of each test case contains two space-separated integers N, S. (1 ≤ N ≤ 10^5, 1 ≤ S ≤ 10^9).

The next lines contain N space-separated integers. (1 ≤ A[i] ≤ 10^9).

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case print ‘Y’ if there exist two index i, j such that A[i]+A[j]=S, i≠j. Otherwise, print ‘N’.


Sample Input 1

3
5 6
1 2 3 4 5
2 1
1 2
3 4
2 2 2

Sample Output 1

Y
N
Y

*/


#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, tar;
	cin >> n >> tar;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int i=0,j=n-1;
	while(i<j){
		if(arr[i]+arr[j]>tar) j--;
		else if(arr[i]+arr[j]<tar) i++; 
		else{
			cout<<"Y"<<endl;
			return;
		}
	}
	cout << "N" << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
