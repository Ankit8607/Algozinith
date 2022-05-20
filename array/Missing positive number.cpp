// https://www.learning.algozenith.com/problems/Missing-positive-number-544

/*

Description

You are given an unsorted array of N integers. Your task is to find the smallest positive integer which is missing in the array.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 10000)

The first line of each test case contains an integer N, 1≤N≤10^5.

The next line contains N space-separated integers, -10^6 ≤ A[i] ≤ 10^6.

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case print in a new line first missing positive integer.


Sample Input 1

5
5
-1 2 4 1 5
5
1 4 3 8 2
5
1 7 8 5 2
5
-1 -2 -3 -4 -5
5
2 1 4 -6 8

Sample Output 1

3
5
3
1
3

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
    int n; cin>>n; 
    int arr[n+5];
    for(int i=0;i<n+5;i++) arr[i]=0;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        if(a>0 and a<=n+1) arr[a]++;
    }
    for(int i=1;i<=n+1;i++){
        if(arr[i]==0){
            cout<<i<<endl;
            return;
        }
    }
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
	solve();
    return 0;
}
