// https://www.learning.algozenith.com/problems/Excel-Sheet-Column-Number-559

/*

Description

Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number % 10^9+7.

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

Input Format

The first line contains an integer T, the number of test cases (1 ≤ T ≤ 100000).

The first line of each test case contains a string S, columnTitle (1 ≤ |S| ≤ 100000).

Sum of |S| across all test cases ≤ 10^6.
 


Output Format

For each test case print the column number % 10^9+7 in a new line.


Sample Input 1

5
A
Z
ZZZ
ABC
ZACGDFHJTGHUJRTD

Sample Output 1

1
26
18278
731
482368326

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

int power(int a, int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;     
}

void solve(){
    string s; cin>>s;
	int ans=0,pw=1;
	for(int i=s.size()-1;i>=0;i--){
		ans+=(s[i]-'A'+1)*pw;
		pw*=26;
		ans%=mod;
		pw%=mod;
	}
	cout<<ans<<endl;
}

signed main(){
    IOS
    int t=1; cin>>t; while(t--) 
	solve();
    return 0;
}
