// https://www.learning.algozenith.com/problems/Median-of-two-sorted-array-542

/*

Description

Given two sorted arrays a and b, find the median of obtained array by merging both arrays.

Note that arrays can be of different sizes. If overall array size is even, then overall median will be the average of the two medians, (integer division).


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 10000)

The first line of each test case contains 2 space-separated integers N, M. 1 ≤ N, M ≤ 100000.

The next line contains N space-separated integers, 1 ≤ A[i] ≤ 10^6.

The next line contains M space-separated integers, 1 ≤ B[i] ≤ 10^6.

Sum of N+M across all test cases ≤ 5*10^6.


Output Format

For each test case print the median.


Sample Input 1

2
2 4
1 2
3 4 5 6
2 5
1 2
3 4 5 6 7

Sample Output 1

3
4

*/


#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
bool check(int mid,int k,vector<int> &a,vector<int> &b){
    auto it=upper_bound(a.begin(),a.end(),mid)-a.begin();
    auto ip=upper_bound(b.begin(),b.end(),mid)-b.begin();
    return it+ip>=k;
}
int find_k(int k,vector<int> &a,vector<int> &b){
    int lo=1,hi=1e6;
    int ans;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid,k,a,b)){
        	ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n),brr(m);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<m;i++) cin>>brr[i];
    if((n+m)%2==1){
        int k=(n+m+1)/2;
        cout<<find_k(k,arr,brr)<<"\n";
    }
    else{
        int k=(n+m)/2;
        int val=find_k(k+1,arr,brr)+find_k(k,arr,brr);
        cout<<val/2<<"\n";
    }
}
signed main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
