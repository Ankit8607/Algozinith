// https://www.learning.algozenith.com/problems/Non-Consecutive-Sum-591

/*

Description

Given an array A of size N, you have to find the subset with the maximum sum such that the subset does not contain any adjacent elements.


Input Format

The first line of each test case contains a single integer N - the size of the array A.
The second line contains N integers - the elements of the array A.


Output Format

For each test case print in a new line the maximum sum possible.


Constraints

1 ≤ N ≤ 105

1≤ A[i] ≤ 109


Sample Input 1

3
1 2 3

Sample Output 1

4

Sample Input 2

5
100 50 60 100 20

Sample Output 2

200

Note

In the first test case choose the numbers [ 1 2 3 ] so that the maximum sum is 4.

In the second test case choose the numbers [ 100 50 60 100 20 ] so that the max sum is 200.

*/



#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    long long taken=0,nottaken=0; 
    while(n--){
        int a ; cin>>a;
        long long tmp=taken;
        taken=a+nottaken;
        nottaken=max(tmp,nottaken);
    }
    cout<<max(nottaken,taken)<<"\n";
    return 0;
}
