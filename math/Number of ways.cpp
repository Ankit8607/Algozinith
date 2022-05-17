// https://www.learning.algozenith.com/problems/Number-of-ways-536

/*

Description

Given an integer N, find the number of ways we can express it as the sum of one or more consecutive non-negative integers.


Input Format

The first line contains an integer T, the number of test cases. (1 ≤ T ≤ 10000).

The first line of each test case contains an integer N (1 ≤ N ≤ 10^8).

 


Output Format

For each test case print the number of ways in a new line.


Sample Input 1

5
15
6
100
150
121

Sample Output 1

5
3
3
6
3

Note

For 15 - 

0 + 1 + 2 + 3 + 4 + 5

1 + 2 + 3 + 4 + 5

4 + 5 + 6

7 + 8

15

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
    int ans=0,i=1;
    while(1){
        int t=2*n-i*(i-1);
        if(t<0)break;
        if(t%(2*i)==0) ans++;
        i++;
    }
    cout<<ans<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
	solve();
    return 0;
}
