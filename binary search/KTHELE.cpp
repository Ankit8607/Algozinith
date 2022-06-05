// https://www.learning.algozenith.com/problems/KTHELE-588

/*

Description

Given two sorted arrays of size N and M, you have to find the Kth element if you merge these two arrays and sort the final array. 

Expected Time Complexity - O(log(N) + log(M))


Input Format

The first line contains three integers N, M and K.

The second line contains N integers - elements of the first array.

The third line contains M integers - elements of the second array.


Output Format

Print the Kth element of the final array.


Constraints

1 ≤ N,M ≤ 105

1 ≤ K ≤ N+M

1 ≤ A[i] ≤ 106


Sample Input 1

3 3 4

1 2 3

4 5 6


Sample Output 1

4


Sample Input 2

5 4 5

2 3 6 7 9

1 4 8 10


Sample Output 2

6


Note

The array elements after sorting in the first test case [1,2,3,4,5,6]

The array elements after sorting in the second test case [1,2,3,4,6,7,8,9,10]

*/



int KthElement(vector<int> &a, vector<int> &b, int k)
{
    int n = (int)a.size();
    int m = (int)b.size();

    int l = 1, r = 1e6, ans;
    while (l <= r)
    {
        int mid = (l + r) / 2, cnt = 0;
        auto it = lower_bound(a.begin(), a.end(), mid);
        if (it != a.begin())
        {
            it--;
            cnt += it - a.begin() + 1;
        }
        it = lower_bound(b.begin(), b.end(), mid);
        if (it != b.begin())
        {
            it--;
            cnt += it - b.begin() + 1;
        }
        if (cnt <= k - 1)
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    return ans;
}
