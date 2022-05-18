// https://www.learning.algozenith.com/problems/Merge-Two-Sorted-Array-540

/*

Description

Given two sorted arrays, print the sorted merge array.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 10000)

The first line of each test case contains 2 space-separated integers N, M. 0 ≤ N, M ≤ 100000.

The next line contains N space-separated integers, 1 ≤ A[i] ≤ 10^6.

The next line contains M space-separated integers, 1 ≤ B[i] ≤ 10^6.


Output Format

For each test case print the sorted merge array.


Sample Input 1

2
3 2
1 2 3
4 5
0 1
5

Sample Output 1

1 2 3 4 5
5

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int mod= 1000000007;
const int N=2000010;
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define ii pair<int,int>
#define all(a) a.begin(),a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define tracearray(arr,n)  cout<<#arr<<endl;for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;

int power(int a, int b,int m){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return ans;     
}


void solve(){
    int n,m; cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int t=n+m;
    int it1=0,it2=0;
    while(t--){
        if(it1<n and it2<m){
            if(a[it1]<=b[it2]){
                cout<<a[it1]<<" ";
                it1++;
            }
            else{
                cout<<b[it2]<<" ";
                it2++;
            }
        }
        else if(it1<n){
            cout<<a[it1]<<" ";
            it1++;
        }
        else {
            cout<<b[it2]<<" ";
            it2++;
        }
    }
    cout<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
	solve();
    return 0;
}
