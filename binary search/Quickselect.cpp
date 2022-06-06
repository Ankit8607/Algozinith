// https://www.learning.algozenith.com/problems/Quickselect-522

/*

Description

Find the K-th smallest element in an unordered list.

Complete the function

int quickSelect(vector<int> num, int K)


Input Format

The first line of input contains N and K.
The second line contains N space-separated integers - A0, A1, …, AN


Output Format

Print the Kth smallest element.


Constraints

1 ≤ K ≤ N ≤ 106
0 ≤ Ai ≤ 109


Sample Input 1

1 1
5

Sample Output 1

5

Sample Input 2

5 3
1 8 7 6 9

Sample Output 2

7

*/


Solution 1:

int quickselect(vector<int> A, int k) 
{
    sort(A.begin(), A.end());
    return A[k - 1];
}
 

Solution 2:

int partition(vector<int> &A, int l, int r)
{
    int x = A[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (A[j] <= x) {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[r]);
    return i;
}

int kthSmallest(vector<int> &A, int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1) {
        int index = partition(A, l, r);

        if (index - l == k - 1)
            return A[index];

        if (index - l > k - 1)
            return kthSmallest(A, l, index - 1, k);

        return kthSmallest(A, index + 1, r, k - index + l - 1);
    }

    return -1;
}

int quickselect(vector<int> A, int k) 
{
    return kthSmallest(A, 0, (int)A.size() - 1, k);
}
