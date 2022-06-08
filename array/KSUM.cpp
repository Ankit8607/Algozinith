// https://www.learning.algozenith.com/problems/KSUM-572

/*

Description

Given an array A of size N, you have to find the longest sub-array of such that the sum of all elements in the sub-array is divisible by K.


Input Format

The first line of each test case contains two integers N and K.
The second line contains N integers - the elements of the array A.


Output Format

For each test case, print the length of the longest sub-array satisfying the given condition in a new line.


Constraints

1 ≤ N ≤ 2 x 105
1 ≤ K ≤ 2 x 105
-109 ≤ A[i] ≤ 109
 


Sample Input 1

6 3
2 7 6 1 4 5
 


Sample Output 1

4
 


Sample Input 2

14 10
10 16 8 13 19 16 2 2 12 6 4 15 13 2


Sample Output 2

11


Note

In the first test case the sum of the segment [7 6 1 4] is 18 which is divisible by 3 and it is the longest segment with sum divisible by 3.

*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k; cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int rem[k]={0},ans=0;
    long long sum=0;
    for(int i=0; i<n; i++){
        (sum+=arr[i])%=k;
        sum=(sum+k)%k;
        if(sum%k==0) ans=i+1;
        else if(rem[sum%k]) ans=max(ans,i-rem[sum%k]+1);
        else rem[sum%k]=i+1;
    }
    cout<<ans<<endl;
}
