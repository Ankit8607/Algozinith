// https://www.learning.algozenith.com/problems/Nearly-Sorted-Arrays-581

/*

Description

You are given an array of n elements where each element is at most k away from its target position in the sorted array. The task is to print the array in sorted order.

Complete the function

void NearlySort(vector<int> &A, int k)

Input Format

The first line of input contains two integers n and k.
The second line contains n integers which represents the input array.


Output Format

Output the input array in sorted order.


Constraints

1 <= n <= 100000
0 <= k < n

Sample Input 1

7 2
10 14 11 20 64 15 70

Sample Output 1

10 11 14 15 20 64 70

Note

The array in sorted order is 10 11 14 15 20 64 70.
10 did not move.
11 moved by 1 place.
14 moved by 1 place.
20 moved by 1 place.
64 moved by 1 place.
15 moved by 2 places.
70 did not move.
So we can see that each number was not more than 2 away from their target position.

*/


#include <bits/stdc++.h>
using namespace std;

void NearlySort(vector<int> &A, int k)
{
    int n = (int)A.size();

    priority_queue<int> pq;

    for (int i = 0; i <= k; i++)
        pq.push(-A[i]);

    int j = 0;

    for (int i = k + 1; i < n; i++)
    {
        A[j++] = -pq.top();
        pq.pop();
        pq.push(-A[i]);
    }

    while (!pq.empty())
    {
        A[j++] = -pq.top();
        pq.pop();
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);

	for (auto &i : v)
		cin >> i;

	NearlySort(v, k);

	for (int i = 0; i < n; i++)
		cout << v[i] << " ";

	cout << "\n";

	return 0;
}
