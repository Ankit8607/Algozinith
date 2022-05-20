// https://www.learning.algozenith.com/problems/AlgoZenith-548

/*

Description

Write a program that outputs the string representation of numbers from 1 to N.

But for multiples of three it should output “Algo” instead of the number and for the multiples of five output “Zenith”. For numbers which are multiples of both three and five output “AlgoZenith”.


Input Format

The first line contains an integer N (1 ≤ N ≤ 10^5).


Output Format

Print the string representation of all numbers from 1 to N in a new line.


Sample Input 1

20

Sample Output 1

1
2
Algo
4
Zenith
Algo
7
8
Algo
Zenith
11
Algo
13
14
AlgoZenith
16
17
Algo
19
Zenith

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
    for(int i=1; i<=n; i++){
        if(i%15==0) cout<<"AlgoZenith"<<endl;
        else if(i%3==0) cout<<"Algo"<<endl;
        else if(i%5==0) cout<<"Zenith"<<endl;
        else cout<<i<<endl;
    }
}

signed main(){
    IOS
    // int t=1; cin>>t; while(t--) 
	solve();
    return 0;
}
