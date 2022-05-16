// https://www.learning.algozenith.com/problems/Array-Product-528

/*

Description

Given an array a of n integers. You need to calculate an array product where product[i] is equal to the product of all elements of a except a[i] itself modulo M. 


Input Format

The first line contains an integer n, m the number of bulbs, and modulus. (1 ≤ n ≤ 10^5, 1 ≤ m ≤ 10^9).

The next lines contain n space-separated integers, integers are distinct, (1 ≤ a[i] ≤ 10^6).


Output Format

Print the product array.


Sample Input 1

5 2
2 4 5 6 7

Sample Output 1

0 0 0 0 0 0 0 0 0 0

Sample Input 2

10 19
2 6 9 3 6 9 108 18 18 18

Sample Output 2

10 16 17 13 16 17 3 18 18 18

*/

#include <bits/stdc++.h>
using namespace std;
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int n,m;
   cin>>n>>m;
   int arr[n];
   long long prefixProduct[n+1];
   long long suffixProduct[n+1];
   for(int i=0;i<=n;i++){
       prefixProduct[i]=1;
       suffixProduct[i]=1;
   }
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
   for(int i=2;i<=n;i++){
       prefixProduct[i] = prefixProduct[i-1]*arr[i-2]%m;
   }
   for(int i=n-1;i>=1;i--){
       suffixProduct[i] = suffixProduct[i+1]*arr[i]%m;
   }
   for(int i=1;i<=n;i++){
       cout<<(prefixProduct[i]*suffixProduct[i])%m<<" ";
   }
}
