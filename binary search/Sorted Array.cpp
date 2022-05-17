// https://www.learning.algozenith.com/problems/Sorted-Array-539

/*

Description

Given a sorted array and a target value, find the first and last position of the target value in the given sorted array.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 10000)

The first line of each test case contains an integer N, 1 ≤ N ≤ 10^5.

The next line of each test case contains N space-separated integers, 1 ≤ A[i] ≤ 10^6.

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case print the first and last position of the target value. If target value does not exist print -1.


Sample Input 1

2
5 2
1 2 2 3 4
5 1
2 2 3 4 5

Sample Output 1

2 3
-1

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
    int n,t; cin>>n>>t;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int a=lower_bound(arr,arr+n,t)-arr;
    int b=upper_bound(arr,arr+n,t)-arr;
    if(a==b) cout<<-1<<endl;
    else cout<<a+1<<" "<<b<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
	solve();
    return 0;
}
